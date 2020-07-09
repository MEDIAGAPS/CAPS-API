#ifndef _MEDIAGAPS_MEMORY_BufferDataSharedPtr_H_
#define _MEDIAGAPS_MEMORY_BufferDataSharedPtr_H_
#include "MediaGaps/ISharedPtr.h"
#include "MediaGaps/Memory/IBufferData.h"

namespace MediaGaps
{
	namespace Memory
	{
		class MEDIAGAPS_EXPORTS_KEYWORD BufferDataSharedPtr : public ISharedPtr<IBufferData, BufferDataSharedPtr>
		{
			struct Impl;
			Impl* _impl;

		public:

			BufferDataSharedPtr();

			explicit BufferDataSharedPtr(IBufferData* sample);

			BufferDataSharedPtr(const BufferDataSharedPtr& other);

			virtual BufferDataSharedPtr& operator=(const BufferDataSharedPtr& other);

			virtual bool operator==(const BufferDataSharedPtr& other);

			~BufferDataSharedPtr();

			virtual IBufferData* Get() const;

			virtual IBufferData* operator->() const;

			virtual IBufferData& operator*() const;

			virtual void Reset();

			virtual void Reset(IBufferData* sample);
		};
	}
}
#endif
