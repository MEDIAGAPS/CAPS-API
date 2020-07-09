#ifndef _MEDIAGAPS_MEDIA_IMEDIACHUNKSIZEPROVIDER_H
#define _MEDIAGAPS_MEDIA_IMEDIACHUNKSIZEPROVIDER_H

#include "MediaGaps/Media/TrackDescriptor.h"

namespace MediaGaps
{
namespace Media
{
    class IMediaChunkSizeProvider
    {
    public:
        virtual ~IMediaChunkSizeProvider() = default;

        virtual UInt32 chunk_size(const TrackDescriptor& track_descriptor) const = 0;
    };
}
}
#endif _MEDIAGAPS_MEDIA_IMEDIACHUNKSIZEPROVIDER_H