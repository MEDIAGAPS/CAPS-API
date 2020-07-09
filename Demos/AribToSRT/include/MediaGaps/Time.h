#ifndef _MEDIAGAPS_TIME_H_
#define _MEDIAGAPS_TIME_H_

#include "MediaGaps/Types.h"

namespace MediaGaps
{
    struct TimeData
    {
        UInt16 Year;
        UInt16 Month;
        UInt16 Day;
        UInt16 Hour;
        UInt16 Minute;
        UInt16 Second;
        UInt16 Milliseconds;
        Int8 UTCOffset;
    };
}

#endif _MEDIAGAPS_TIME_H_
