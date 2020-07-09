#ifndef _MEDIAGAPS_TS_PATDATA_H
#define _MEDIAGAPS_TS_PATDATA_H

#include "MediaGaps/Ts/ProgramDataList.h"

namespace MediaGaps
{
	namespace Ts
	{
		struct PatData
		{
			UInt16 tsId;
			UInt8 version;
			bool currentNext;

			ProgramDataList programDataList;
		};
	}
}
#endif // _MEDIAGAPS_TS_PATDATA_H
