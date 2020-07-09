#ifndef _MEDIAGAPS_MEDIA_SAMPLEPROVIDERPTR_H_
#define _MEDIAGAPS_MEDIA_SAMPLEPROVIDERPTR_H_

#include "MediaGaps/Media/ISampleProvider.h"

namespace MediaGaps
{
	namespace Media
	{
		class MEDIAGAPS_EXPORTS_KEYWORD SampleProviderSharedPtr
		{
			struct Impl;
			Impl* _impl;

		public:
			SampleProviderSharedPtr();

			explicit SampleProviderSharedPtr(ISampleProvider* sampleProvider);

			SampleProviderSharedPtr(const SampleProviderSharedPtr& other);

			SampleProviderSharedPtr& operator=(const SampleProviderSharedPtr& other);

			~SampleProviderSharedPtr();

			ISampleProvider* Get() const;

			ISampleProvider* operator->() const;

			void Reset();

			void Reset(ISampleProvider* sampleProvider);
		};
	}
}

#endif // _MEDIAGAPS_MEDIA_SAMPLEPROVIDERPTR_H_
