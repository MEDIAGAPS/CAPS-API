#ifndef _MEDIAGAPS_IO_ISINKSHAREDPTR_H_
#define _MEDIAGAPS_IO_ISINKSHAREDPTR_H_

#include "MediaGaps/IO/ISink.h"
#include "MediaGaps/ISharedPtr.h"

namespace MediaGaps
{
	namespace IO
	{
		class MEDIAGAPS_EXPORTS_KEYWORD SinkSharedPtr : public ISharedPtr<ISink, SinkSharedPtr>
		{
			struct Impl;
			Impl* _impl;

		public:
			SinkSharedPtr();

			explicit SinkSharedPtr(ISink* sample);

			SinkSharedPtr(const SinkSharedPtr& other);

			virtual SinkSharedPtr& operator=(const SinkSharedPtr& other);

			virtual bool operator==(const SinkSharedPtr& other);

			~SinkSharedPtr();

			virtual ISink* Get() const;

			virtual ISink* operator->() const;

			virtual ISink& operator*() const;

			virtual void Reset();

			virtual void Reset(ISink* sample);
		};
	}
}

#endif // _MEDIAGAPS_IO_ISINKSHAREDPTR_H_
