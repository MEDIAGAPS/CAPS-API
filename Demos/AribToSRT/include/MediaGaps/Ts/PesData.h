#ifndef _MEDIAGAPS_TS_PESDATA_H
#define _MEDIAGAPS_TS_PESDATA_H

#include "MediaGaps/Ts/DescriptorDataList.h"

namespace MediaGaps
{
	namespace Ts
	{
		struct MEDIAGAPS_EXPORTS_KEYWORD PesData
		{
			UInt8 type;
			UInt16 pid;
			DescriptorDataList descriptorDataList;

			PesData();

			bool operator==(PesData pesData);

			bool operator!=(PesData pesData);
		};
	}
}
#endif // _MEDIAGAPS_TS_PESDATA_H
