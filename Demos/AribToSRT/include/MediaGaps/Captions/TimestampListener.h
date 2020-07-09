#ifndef _MEDIAGAPS_CAPTIONS_TIMESTAMPLISTENER_H_
#define _MEDIAGAPS_CAPTIONS_TIMESTAMPLISTENER_H_

#include "MediaGaps/Types.h"
#include "MediaGaps/Exports.h"


namespace MediaGaps
{
	namespace Captions{
	class MEDIAGAPS_EXPORTS_KEYWORD TimestampListener
	{
	public:

		virtual ~TimestampListener() = default;

		virtual void SetInitialTimestamp(UInt64 timestamp) = 0;
	};
}
}

#endif //_MEDIAGAPS_CAPTIONS_TIMESTAMPLISTENER_H_
 