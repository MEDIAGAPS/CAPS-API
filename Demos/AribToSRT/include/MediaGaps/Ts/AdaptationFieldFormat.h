#ifndef _MEDIAGAPS_TS_ADAPTATIONFIELDFORMAT_H
#define _MEDIAGAPS_TS_ADAPTATIONFIELDFORMAT_H

#include "MediaGaps/Types.h"

namespace MediaGaps
{
	namespace Ts
	{
#pragma pack(push, 1)
		struct MPEGTSAdaptationFieldFormat
		{
			UInt8 adaptationFieldLength : 8;

			UInt8 AdaptationFieldExtensionFlag : 1;
			UInt8 transportPrivateDataFlag : 1;
			UInt8 splicingPointFlag : 1;
			UInt8 opcrFlag : 1;
			UInt8 pcrFlag : 1;
			UInt8 elementaryStreamPriorityIndicator : 1;
			UInt8 randomAccessIndicator : 1;
			UInt8 discontinuityIndicator : 1;
		};
#pragma pack(pop)

#pragma pack(push, 1)
		struct MPEGTSPcrOpcr
		{
			UInt8 pcr1 : 8;
			UInt8 pcr2 : 8;
			UInt8 pcr3 : 8;
			UInt8 pcr4 : 8;
			UInt8 pcr5 : 8;
			UInt8 pcr6 : 8;
		};
#pragma pack(pop)

#pragma pack(push, 1)
		struct MPEGTSSpliceCountdown
		{
			UInt8 spliceCountdown : 8;
		};
#pragma pack(pop)
	}

	enum AdaptationFieldControl
	{
		AdaptationFieldControl_ReservedForFutureUse = 0,
		AdaptationFieldControl_NoAdaptationFieldPayloadOnly = 1,
		AdaptationFieldControl_AdaptationFieldOnlyNoPayload = 2,
		AdaptationFieldControl_AdaptationFieldFollowedByPayload = 3
	};
}
#endif // _MEDIAGAPS_TS_ADAPTATIONFIELDFORMAT_H
