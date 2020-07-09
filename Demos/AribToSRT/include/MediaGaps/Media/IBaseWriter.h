#ifndef _MEDIAGAPS_MEDIA_IBASEWRITER_H_
#define _MEDIAGAPS_MEDIA_IBASEWRITER_H_

#include "MediaGaps/Media/TrackDescriptor.h"
#include "MediaGaps/Media/SampleProviderSharedPtr.h"

namespace MediaGaps
{
    namespace Media
    {
        class MEDIAGAPS_EXPORTS_KEYWORD IBaseWriter
        {
        public:
            virtual ~IBaseWriter();

            virtual void AddTrack(const TrackDescriptor& trackDescriptor, SampleProviderSharedPtr sampleProviderSharedPtr) = 0;
        };
    }
}

#endif //_MEDIAGAPS_MEDIA_IBASEWRITER_H_
