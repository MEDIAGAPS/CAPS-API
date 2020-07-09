#ifndef _MEDIAGAPS_TS_MUX_MUXERWITHMUTEX_H_
#define _MEDIAGAPS_TS_MUX_MUXERWITHMUTEX_H_

#include "MediaGaps/IO/SinkSharedPtr.h"
#include "MediaGaps/Ts/Mux/IMuxer.h"

namespace MediaGaps
{
	namespace Ts
	{
		namespace Mux
		{
			class MEDIAGAPS_EXPORTS_KEYWORD MuxerWithMutex : public IMuxer
			{
				struct Impl;
				Impl* _impl;

			public:
				explicit MuxerWithMutex(IO::SinkSharedPtr sink);

				~MuxerWithMutex();

				void AddPat(const PatData& data) override;

				void AddPmt(const PmtData& data, UInt16 packetId) override;

				void AddPesPacket(UInt16 packetId, const unsigned char* data, UInt64 size) override;
			};
		}
	}
}

#endif // _MEDIAGAPS_TS_MUX_MUXERWITHMUTEX_H_
