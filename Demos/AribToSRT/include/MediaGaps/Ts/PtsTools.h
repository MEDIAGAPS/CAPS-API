#ifndef _MEDIAGAPS_TS_PTSTOOLS_H_
#define _MEDIAGAPS_TS_PTSTOOLS_H_

#include "MediaGaps/Types.h"
#include "MediaGaps/Exports.h"

namespace MediaGaps
{
	namespace Ts
	{
		namespace PtsTools
		{
			MEDIAGAPS_EXPORTS_KEYWORD UInt64 LoadPts(const unsigned char* value);

			MEDIAGAPS_EXPORTS_KEYWORD void WritePts(UInt64 value, unsigned char* writeLocation);
		}
	}
}

#endif //_MEDIAGAPS_TS_PTSTOOLS_H_
