#ifndef _MEDIAGAPS_MEDIA_ISAMPLEPROVIDER_H_
#define _MEDIAGAPS_MEDIA_ISAMPLEPROVIDER_H_

#include "MediaGaps/Media/MediaSampleSharedPtr.h"

namespace MediaGaps
{
    namespace Media
    {
        class MEDIAGAPS_EXPORTS_KEYWORD ISampleProvider
        {
        public:
            /** Destructor.
            */
            virtual ~ISampleProvider();

            /** Returns a new sample.
            * \return a new sample, when no more samples are available a pointer to zero.
            */
            virtual MediaSampleSharedPtr GetNextSample() = 0;

			/** Indicates if a next sample is available to return
		 */
			virtual bool IsNextSampleAvailable() const = 0;

            /** Aborts the current process.
            */
            virtual void Abort() = 0;
        };
    }
}

#endif // _MEDIAGAPS_MEDIA_ISAMPLEPROVIDER_H_
