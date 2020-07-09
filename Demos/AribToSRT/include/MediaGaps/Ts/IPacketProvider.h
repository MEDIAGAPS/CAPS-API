#ifndef _MEDIAGAPS_TS_IPACKETPROVIDER_H_
#define _MEDIAGAPS_TS_IPACKETPROVIDER_H_

#include "MediaGaps/Memory/BufferDataSharedPtr.h"

namespace MediaGaps
{
	namespace Ts
	{
		class MEDIAGAPS_EXPORTS_KEYWORD IPacketProvider
		{
		public:
			virtual ~IPacketProvider() {}

			virtual Memory::BufferDataSharedPtr GetPacket() = 0;
		};
	}
}

#endif // _MEDIAGAPS_TS_IPACKETPROVIDER_H_
