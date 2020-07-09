#ifndef _MEDIAGAPS_MEDIA_TRACKDESCRIPTORSHAREDPTR_H_
#define _MEDIAGAPS_MEDIA_TRACKDESCRIPTORSHAREDPTR_H_

#include "MediaGaps/Media/TrackDescriptor.h"

namespace MediaGaps
{
	namespace Media
	{
		class MEDIAGAPS_EXPORTS_KEYWORD TrackDescriptorSharedPtr
		{
			struct Impl;
			Impl* _impl;

		public:
			TrackDescriptorSharedPtr();

			explicit TrackDescriptorSharedPtr(TrackDescriptor* sample);

			TrackDescriptorSharedPtr(const TrackDescriptorSharedPtr& other);

			TrackDescriptorSharedPtr& operator=(const TrackDescriptorSharedPtr& other);

			bool operator==(const TrackDescriptorSharedPtr& other);

			~TrackDescriptorSharedPtr();

			TrackDescriptor* Get() const;

			TrackDescriptor* operator->() const;

			TrackDescriptor& operator*() const;

			void Reset() const;

			void Reset(TrackDescriptor* sample) const;
		};
	}
}

#endif // _MEDIAGAPS_MEDIA_TRACKDESCRIPTORSHAREDPTR_H_
