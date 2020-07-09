#ifndef _MEDIAGAPS_TS_PTSLISTENER_H_
#define _MEDIAGAPS_TS_PTSLISTENER_H_

#include "MediaGaps/Types.h"
#include "MediaGaps/Exports.h"

namespace MediaGaps
{
	namespace Ts
	{
		class MEDIAGAPS_EXPORTS_KEYWORD PtsListener
		{
		public:
			virtual ~PtsListener() = default;

			virtual void NewPts(UInt64 pts) = 0;
		};
	}
}
#endif //_MEDIAGAPS_TS_PTSLISTENER_H_
