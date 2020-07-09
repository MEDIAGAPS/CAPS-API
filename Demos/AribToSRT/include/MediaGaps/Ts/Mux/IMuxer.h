#ifndef _MEDIAGAPS_TS_MUX_IMUXER_H_
#define _MEDIAGAPS_TS_MUX_IMUXER_H_

#include "MediaGaps/Exports.h"
#include "MediaGaps/Ts/PmtData.h"
#include "MediaGaps/Ts/PatData.h"

namespace MediaGaps
{
	namespace Ts
	{
		namespace Mux
		{
			class MEDIAGAPS_EXPORTS_KEYWORD IMuxer
			{
			public:
				virtual ~IMuxer() = default;

				virtual void AddPat(const PatData& data) = 0;

				virtual void AddPmt(const PmtData& data, UInt16 packetId) = 0;

				virtual void AddPesPacket(UInt16 packetId, const unsigned char* data, UInt64 size) = 0;
			};
		}
	}
}
#endif // _MEDIAGAPS_TS_MUX_IMUXER_H_
