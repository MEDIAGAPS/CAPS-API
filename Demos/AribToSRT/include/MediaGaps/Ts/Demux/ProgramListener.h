#ifndef _MEDIAGAPS_TS_DEMUX_PROGRAMLISTENER_H_
#define _MEDIAGAPS_TS_DEMUX_PROGRAMLISTENER_H_

#include "MediaGaps/Exports.h"
#include "MediaGaps/Ts/PmtData.h"

namespace MediaGaps
{
	namespace Ts
	{
		namespace Demux
		{
			class MEDIAGAPS_EXPORTS_KEYWORD ProgramListener
			{
			public:
				virtual ~ProgramListener() = default;

				virtual void HandlePMT(const PmtData& data) = 0;

				virtual void HandlePESPacket(UInt16 packetId, const unsigned char* data, UInt64 size) = 0;
			};
		}
	}
}
#endif //_MEDIAGAPS_TS_DEMUX_PROGRAMLISTENER_H_
