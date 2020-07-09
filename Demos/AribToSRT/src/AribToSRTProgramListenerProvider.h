#ifndef _ARIBTOSRTPROGRAMLISTENERPROVIDER_H_
#define _ARIBTOSRTPROGRAMLISTENERPROVIDER_H_

#include "MediaGaps/Captions/Arib/AribParserSharedPtr.h"
#include "MediaGaps/Ts/Demux/ProgramListenerProvider.h"

#include <memory>
#include <vector>
#include <map>

namespace MediaGaps
{
	typedef std::vector<UInt16> AribPidVector;
	typedef std::map<UInt16, Captions::Arib::AribParserSharedPtr> AribParserMap;
	typedef std::vector<Captions::SubtitleListenerSharedPtr> ISubtitleListenerPtrVector;

	class AribToSRTProgramListenerProvider : public Ts::Demux::ProgramListenerProvider,
	                                         public Ts::Demux::ProgramListener
	{
		AribPidVector _aribIds;

		std::wstring _srtLocation;
		AribParserMap _aribParserMap;

		std::unique_ptr<UInt64> _initialPresentationTimestamp;
		std::unique_ptr<UInt16> _videoPid;

	public:
		explicit AribToSRTProgramListenerProvider(const wchar_t* srtLocation);

		Ts::Demux::ProgramListenerSharedPtr NewProgramListener(UInt16 programId) override;

		void HandlePat(const Ts::PatData& data) override;

		void HandleGenericPacket(UInt16 packetId, const unsigned char* data, UInt64 size) override;

		void HandleUnknownPacket(UInt16 packetId, const unsigned char* data, UInt64 size) override;

		void HandlePMT(const Ts::PmtData& data) override;

		void HandlePESPacket(UInt16 packetId, const unsigned char* data, UInt64 size) override;

		void LoadInitialVideoPts(const unsigned char* data);
	};
}
#endif // _ARIBTOSRTPROGRAMLISTENERPROVIDER_H_
