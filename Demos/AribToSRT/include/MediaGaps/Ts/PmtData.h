#ifndef _MEDIAGAPS_TS_PMTDATA_H
#define _MEDIAGAPS_TS_PMTDATA_H

#include "MediaGaps/Ts/DescriptorDataList.h"
#include "MediaGaps/Ts/PesDataList.h"

namespace MediaGaps
{
	namespace Ts
	{
		struct MEDIAGAPS_EXPORTS_KEYWORD PmtData
		{
			UInt16 programNumber;
			UInt8 version;
			bool currentNext;
			UInt16 pcrPid;
			DescriptorDataList descriptorDataList;
			PesDataList pesDataList;

			PmtData();

			bool operator==(PmtData pmtData);
		};
	}
}
#endif // _MEDIAGAPS_TS_PMTDATA_H
