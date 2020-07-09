#ifndef _MEDIAGAPS_TS_PROGRAMDATA_H
#define _MEDIAGAPS_TS_PROGRAMDATA_H

#include "MediaGaps/Types.h"

namespace MediaGaps
{
	namespace Ts
	{
		struct ProgramData
		{
			UInt16 programNumber;
			UInt16 programPid;

			ProgramData();

			ProgramData(UInt16 programNumberValue, UInt16 programPidValue);
			
			bool operator==(ProgramData programData);
		};
	}
}
#endif // _MEDIAGAPS_TS_PROGRAMDATA_H
