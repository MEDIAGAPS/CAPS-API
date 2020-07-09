#ifndef _MEDIAGAPS_MEDIA_MEDIASAMPLESHAREDPTR_H_
#define _MEDIAGAPS_MEDIA_MEDIASAMPLESHAREDPTR_H_

#include "MediaGaps/Media/IMediaSample.h"

namespace MediaGaps
{
    namespace Media
    {
        class MEDIAGAPS_EXPORTS_KEYWORD MediaSampleSharedPtr
        {
            struct Impl;
            Impl* _impl;

        public:
            MediaSampleSharedPtr();

            explicit MediaSampleSharedPtr(IMediaSample* sample);

            MediaSampleSharedPtr(const MediaSampleSharedPtr& other);

            MediaSampleSharedPtr& operator=(const MediaSampleSharedPtr& other);

            ~MediaSampleSharedPtr();

            IMediaSample* Get() const;

            IMediaSample* operator->() const;
			IMediaSample& operator*() const;

            void Reset();

            void Reset(IMediaSample* sample);
        };
    }
}

#endif // _MEDIAGAPS_MEDIA_MEDIASAMPLESHAREDPTR_H_
