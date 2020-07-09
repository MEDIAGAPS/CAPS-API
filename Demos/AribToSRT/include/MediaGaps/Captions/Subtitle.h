#ifndef _MEDIAGAPS_CAPTIONS_SUBTITLE_H_
#define _MEDIAGAPS_CAPTIONS_SUBTITLE_H_

#include "MediaGaps/Captions/SubtitleText.h"
#include "MediaGaps/Types.h"

namespace MediaGaps
{
	namespace Captions
	{
		struct Subtitle
		{
			UInt64 startTime = 0;
			UInt64 endTime = 0;
			SubtitleText subtitleText ;

			Subtitle() = default;

			Subtitle(UInt64 startTimeValue, UInt64 endTimeValue) :
				startTime(startTimeValue), endTime(endTimeValue) {}
			
			Subtitle(UInt64 startTimeValue, UInt64 endTimeValue, SubtitleText subtitleTextValue) :
				startTime(startTimeValue), endTime(endTimeValue),
				subtitleText(subtitleTextValue) {}
		};
	}
}
#endif // _MEDIAGAPS_CAPTIONS_SUBTITLE_H_
