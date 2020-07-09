#ifndef _MEDIAGAPS_MEDIA_TIMECODE_TIMECODEINFO_H_
#define _MEDIAGAPS_MEDIA_TIMECODE_TIMECODEINFO_H_

#include "MediaGaps/Timecode/Timecode.h"
#include "MediaGaps/NonCopyable.h"

namespace MediaGaps
{
	namespace Media
	{
		class MEDIAGAPS_EXPORTS_KEYWORD TimecodeInfo : NonCopyable
		{
			struct Impl;
			Impl* _impl;

		public:
			/** Constructor.
			*/
			TimecodeInfo();

			/** Destructor.
			*/
			virtual ~TimecodeInfo();

			/** Sets the initial timecode.
			*/
			void SetInitialTimecode(const Timecode& timecode) const;

			/** Returns the initial timecode.
			If timecode was not, returns 0.
			*/
			const Timecode* GetInitialTimecode() const;
		};
	}
}

#endif //_MEDIAGAPS_MEDIA_TIMECODE_TIMECODEINFO_H_
