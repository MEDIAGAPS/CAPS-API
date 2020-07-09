#include "AribToSRTProgramListenerProvider.h"
#include "ProgramListenerAdapter.h"
#include "MediaGaps/Ts/PartialTransportStreamPacketFormat.h"
#include "MediaGaps/Ts/AdaptationFieldFormat.h"
#include "MediaGaps/Captions/SRT/SRTListener.h"
#include "MediaGaps/Ts/PesPacketHeader.h"
#include "MediaGaps/Ts/PtsTools.h"
#include "MediaGaps/Ts/TransportStreamEnums.h"
#include <sstream>

using namespace MediaGaps::Ts::Demux;
using namespace MediaGaps::Ts;
using namespace MediaGaps::Captions::Arib;
using namespace MediaGaps::Captions::SRT;
using namespace MediaGaps::Captions;
using namespace MediaGaps;

namespace
{
	enum TsVideo
	{
		TsVideo_H264 = 0x1b,
		TsVideo_H262 = 0x02
	};
	
	std::tuple<bool, size_t> GetPayloadPosition(const unsigned char* data)
	{
		bool pcrFlag = false;
		bool opcrFlag = false;
		bool spliceCountdownFlag = false;
		bool transportPrivateDataFlag = false;
		bool payloadFlag = false;
		bool adaptionFieldFlag = false;

		size_t dataPosition = 0;

		const unsigned char* headerData = &data[dataPosition];
		dataPosition += sizeof(MPEGTSHeader);
		const auto* mpegTsHeader = reinterpret_cast<const MPEGTSHeader*>(headerData);

		switch (mpegTsHeader->adaptationFieldControl)
		{
			case AdaptationFieldControl_NoAdaptationFieldPayloadOnly:
				{
					payloadFlag = true;
					break;
				}
			case AdaptationFieldControl_AdaptationFieldOnlyNoPayload:
				{
					adaptionFieldFlag = true;
					break;
				}
			case AdaptationFieldControl_AdaptationFieldFollowedByPayload:
				{
					payloadFlag = true;
					adaptionFieldFlag = true;
					break;
				}
			default:
				{
					break;
				}
		}

		int adaptationFieldLength = 0;
		if (adaptionFieldFlag)
		{
			const unsigned char* adaptationFieldControlData = &data[dataPosition];
			dataPosition += sizeof(MPEGTSAdaptationFieldFormat);

			const auto* adaptationFieldFormat = reinterpret_cast<const MPEGTSAdaptationFieldFormat*>(
				adaptationFieldControlData);

			adaptationFieldLength = static_cast<int>(adaptationFieldFormat->adaptationFieldLength);

			if (static_cast<int>(adaptationFieldFormat->pcrFlag) == 1) pcrFlag = true;
			if (static_cast<int>(adaptationFieldFormat->opcrFlag) == 1) opcrFlag = true;
			if (static_cast<int>(adaptationFieldFormat->splicingPointFlag) == 1) spliceCountdownFlag = true;
			if (static_cast<int>(adaptationFieldFormat->transportPrivateDataFlag) == 1)
				transportPrivateDataFlag
						= true;
		}

		if (pcrFlag)
		{
			dataPosition += sizeof(MPEGTSPcrOpcr);
		}

		if (opcrFlag)
		{
			dataPosition += sizeof(MPEGTSPcrOpcr);
		}

		if (spliceCountdownFlag)
		{
			dataPosition += sizeof(MPEGTSSpliceCountdown);
		}

		if (transportPrivateDataFlag)
		{
			dataPosition += sizeof(MPEGTSSpliceCountdown);
		}

		if (adaptationFieldLength != 0)
		{
			dataPosition = adaptationFieldLength + 5;
		}

		return std::make_tuple(payloadFlag, dataPosition);
	}
}

AribToSRTProgramListenerProvider::
AribToSRTProgramListenerProvider(const wchar_t* srtLocation) : _srtLocation(srtLocation) {}

ProgramListenerSharedPtr AribToSRTProgramListenerProvider::NewProgramListener(UInt16 /*programId*/)
{
	return ProgramListenerSharedPtr(new ProgramListenerAdapter(*this));
}

void AribToSRTProgramListenerProvider::HandlePat(const PatData& /*data*/) {}

void AribToSRTProgramListenerProvider::HandleGenericPacket(UInt16 packetId, const unsigned char* data, UInt64 size)
{
	HandlePESPacket(packetId, data, size);
}

void AribToSRTProgramListenerProvider::HandleUnknownPacket(UInt16 packetId, const unsigned char* data, UInt64 size)
{
	HandlePESPacket(packetId, data, size);
}

void AribToSRTProgramListenerProvider::HandlePMT(const PmtData& data)
{
	PmtData pmtData;
	pmtData.programNumber = data.programNumber;
	pmtData.descriptorDataList = data.descriptorDataList;
	pmtData.currentNext = data.currentNext;
	pmtData.pcrPid = data.pcrPid;
	pmtData.version = data.version;

	for (PesDataList::IListConstIterator pesDataIterator = data.pesDataList.ConstBegin(); pesDataIterator !=
	     data.pesDataList.ConstEnd(); ++pesDataIterator)
	{
		PesData pesData;
		pesData.descriptorDataList = (*pesDataIterator).descriptorDataList;
		pesData.type = (*pesDataIterator).type;
		pesData.pid = (*pesDataIterator).pid;

		pmtData.pesDataList.Add(pesData);

		if ((*pesDataIterator).type == 6)
		{
			_aribIds.push_back((*pesDataIterator).pid);
		}

		if ((*pesDataIterator).type == TsVideo_H264 || (*pesDataIterator).type == TsVideo_H262)
		{
			_videoPid.reset(new UInt16((*pesDataIterator).pid));
		}
	}
}

void AribToSRTProgramListenerProvider::HandlePESPacket(UInt16 packetId, const unsigned char* data, UInt64 /*size*/)
{
	if (_initialPresentationTimestamp == nullptr)
	{
		if (_videoPid != nullptr && *_videoPid == packetId)
		{
			LoadInitialVideoPts(data);
		}
	}

	if (std::find(_aribIds.begin(), _aribIds.end(), packetId) != _aribIds.end())
	{
		const auto aribParserMapIterator = _aribParserMap.find(packetId);
		if (aribParserMapIterator == _aribParserMap.end())
		{
			std::wstringstream fileDestSubtitle;
			fileDestSubtitle << _srtLocation << L"/subtitle_id_" << static_cast<
				int>(packetId) << L".srt";

			SubtitleListenerSharedPtr
					listener(new SRTListener(fileDestSubtitle.str().c_str()));

			AribParserSharedPtr aribParser(new AribParser(listener, packetId));
		
			if (_initialPresentationTimestamp != nullptr)
			{
				listener->SetInitialTimestamp(*_initialPresentationTimestamp);
			}

			_aribParserMap.insert(AribParserMap::value_type(packetId, aribParser));
		}

		auto payloadPosition = GetPayloadPosition(data);
		if (std::get<0>(payloadPosition))
		{
			const size_t dataPosition = std::get<1>(payloadPosition);
			const size_t payloadSize = TS_PACKET_SIZE - dataPosition;

			const auto aribIterator = _aribParserMap.find(packetId);
			aribIterator->second->ProcessCaption(data + dataPosition, static_cast<int>(payloadSize));
		}
	}
}

void AribToSRTProgramListenerProvider::LoadInitialVideoPts(const unsigned char* data)
{
	auto payloadPosition = GetPayloadPosition(data);
	if (std::get<0>(payloadPosition))
	{
		size_t dataPosition = std::get<1>(payloadPosition);
		bool havePts = false;

		if (data[dataPosition] == 0x00 && data[dataPosition + 1] == 0x00 && data[dataPosition + 2] == 0x01)
		{
			dataPosition += sizeof(PESPacketHeader);

			const unsigned char* optionalHeaderData = &data[dataPosition];
			dataPosition += sizeof(OptionalPESHeader);
			const auto* optionalPesHeader = reinterpret_cast<const OptionalPESHeader*>(optionalHeaderData);

			switch (optionalPesHeader->ptsDtsIndicator)
			{
				case PtsDtsIndicator_OnlyPts:
					{
						havePts = true;
						break;
					}
				case PtsDtsIndicator_BothPresent:
					{
						havePts = true;
						break;
					}
				default:
					{
						break;
					}
			}
		}

		if (havePts)
		{
			_initialPresentationTimestamp.reset(new UInt64(PtsTools::LoadPts(&data[dataPosition]) / 90));

			for (auto& iterator : _aribParserMap)
			{
				iterator.second->SetInitialTimestamp(*_initialPresentationTimestamp);
			}
		}
	}
}
