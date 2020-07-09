#ifndef _MEDIAGAPS_TS_DESCRIPTORDATA_H
#define _MEDIAGAPS_TS_DESCRIPTORDATA_H

#include "MediaGaps/Types.h"
#include "MediaGaps/UInt8List.h"

namespace MediaGaps
{
	namespace Ts
	{
		typedef UInt8List DescriptorValue;

		struct DescriptorData
		{
			UInt8 tag;
			DescriptorValue value;

			DescriptorData();

			bool operator==(DescriptorData descriptorData);

			bool operator!=(DescriptorData descriptorData);
		};
	}
}
#endif // _MEDIAGAPS_TS_DESCRIPTORDATA_H
