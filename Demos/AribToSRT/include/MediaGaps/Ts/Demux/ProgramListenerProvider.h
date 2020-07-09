#ifndef _MEDIAGAPS_TS_DEMUX_PROGRAMLISTENERPROVIDER_H_
#define _MEDIAGAPS_TS_DEMUX_PROGRAMLISTENERPROVIDER_H_

#include "MediaGaps/Ts/Demux/ProgramListenerSharedPtr.h"
#include "MediaGaps/Ts/PatData.h"

namespace MediaGaps
{
	namespace Ts
	{
		namespace Demux
		{
			class MEDIAGAPS_EXPORTS_KEYWORD ProgramListenerProvider
			{
			public:
				virtual ~ProgramListenerProvider() = default;

				virtual void HandlePat(const PatData& data) = 0;

				virtual ProgramListenerSharedPtr NewProgramListener(UInt16 pid) = 0;

				virtual void HandleGenericPacket(UInt16 packet_id, const unsigned char* data, UInt64 size) = 0;

				virtual void HandleUnknownPacket(UInt16 packet_id, const unsigned char* data, UInt64 size) = 0;
			};
		}
	}
}

#endif //_MEDIAGAPS_TS_DEMUX_PROGRAMLISTENERPROVIDER_H_
