#ifndef _MEDIAGAPS_MEDIA_DATATRACKDESCRIPTOR_H_
#define _MEDIAGAPS_MEDIA_DATATRACKDESCRIPTOR_H_

#include "MediaGaps/Media/TrackDescriptor.h"

namespace MediaGaps
{
    namespace Media
    {
        class MEDIAGAPS_EXPORTS_KEYWORD DataTrackDescriptor : public TrackDescriptor
        {
            struct Impl;
            Impl* _impl;

        public:

            DataTrackDescriptor();

            virtual ~DataTrackDescriptor();

            DataTrackDescriptor(const DataTrackDescriptor&);

            DataTrackDescriptor& operator=(const DataTrackDescriptor&);

            virtual TrackDescriptorSharedPtr Clone() const;

        };
    }
}
#endif // _MEDIAGAPS_MEDIA_DATATRACKDESCRIPTOR_H_
