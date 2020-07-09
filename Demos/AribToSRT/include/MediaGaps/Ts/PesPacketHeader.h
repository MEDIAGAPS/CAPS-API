#ifndef _MEDIAGAPS_TS_PESPACKETHEADER_H_
#define _MEDIAGAPS_TS_PESPACKETHEADER_H_

#include "MediaGaps/Types.h"

namespace MediaGaps
{
	namespace Ts
	{
		enum PtsDtsIndicator
		{
			PtsDtsIndicator_NoPtsOrDts = 0,
			PtsDtsIndicator_IsForbidden = 1,
			PtsDtsIndicator_OnlyPts = 2,
			PtsDtsIndicator_BothPresent = 3
		};

#pragma pack(push, 1)
		struct PESPacketHeader
		{
			UInt8 packetStartCodePrefixHigh : 8;
			UInt8 packetStartCodePrefixMid : 8;
			UInt8 packetStartCodePrefixLow : 8;
			UInt8 streamId : 8;
			UInt8 pesPacketLengthHigh : 8;
			UInt8 pesPacketLengthLow : 8;
		};
#pragma pack(pop)

#pragma pack(push, 1)
		struct OptionalPESHeader
		{
			UInt8 originalOrCopy : 1;
			UInt8 copyright : 1;
			UInt8 dataAlignmentIndicator : 1;
			UInt8 priority : 1;
			UInt8 scramblingControl : 2;
			UInt8 markerBits : 2;

			UInt8 extensionFlag : 1;
			UInt8 crcFlag : 1;
			UInt8 additionalCopyInfoFlag : 1;
			UInt8 dsmTrickModeFlag : 1;
			UInt8 esRateFlag : 1;
			UInt8 escrFlag : 1;
			UInt8 ptsDtsIndicator : 2;

			UInt8 pesHeaderLength : 8;
		};
#pragma pack(pop)

#pragma pack(push, 1)
		struct PTSData
		{
			UInt8 alwaysOne_1 : 1;
			UInt8 pts_30_32 : 3;
			UInt8 pts_flag : 4;

			UInt8 pts_22_29 : 8;

			UInt8 alwaysOne_2 : 1;
			UInt8 pts_15_21 : 7;

			UInt8 pts_7_14 : 8;

			UInt8 alwaysOne_3 : 1;
			UInt8 pts_0_6 : 7;
		};
#pragma pack(pop)
	}
}

#endif // _MEDIAGAPS_TS_PESPACKETHEADER_H_
