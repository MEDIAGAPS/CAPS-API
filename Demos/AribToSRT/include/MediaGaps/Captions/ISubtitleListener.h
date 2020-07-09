#ifndef _MEDIAGAPS_CAPTIONS_ISUBTITLELISTENER_H_
#define _MEDIAGAPS_CAPTIONS_ISUBTITLELISTENER_H_

#include "MediaGaps/Captions/Subtitle.h"
#include "MediaGaps/Captions/TimestampListener.h"

namespace MediaGaps
{
	namespace Captions
	{
		class MEDIAGAPS_EXPORTS_KEYWORD ISubtitleListener : public TimestampListener
		{
		public:
			virtual ~ISubtitleListener() = default;

			virtual void HandleNewSubtitle(const Subtitle& subtitle) = 0;
		};
	}
}
#endif // _MEDIAGAPS_CAPTIONS_ISUBTITLELISTENER_H_
