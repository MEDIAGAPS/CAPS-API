#ifndef _MEDIAGAPS_TS_PARTIALTRANSPORTSTREAMPACKETFORMAT_H
#define _MEDIAGAPS_TS_PARTIALTRANSPORTSTREAMPACKETFORMAT_H

#include "MediaGaps/Types.h"

namespace MediaGaps
{
	namespace Ts
	{
#pragma pack(push, 1)
		struct MPEGTSHeader
		{
			UInt8 syncByte : 8;

			UInt8 pidHigh : 5;
			UInt8 transportPriority : 1;
			UInt8 payloadUnitStartIndicator : 1;
			UInt8 transportErrorIndicator : 1;

			UInt8 pidLow : 8;

			UInt8 continuityCounter : 4;
			UInt8 adaptationFieldControl : 2;
			UInt8 transportScramblingControl : 2;
		};

#pragma pack(pop)
	}
}

#endif // _MEDIAGAPS_TS_PARTIALTRANSPORTSTREAMPACKETFORMAT_H
