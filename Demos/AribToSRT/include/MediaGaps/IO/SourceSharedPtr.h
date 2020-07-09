#ifndef _MEDIAGAPS_IO_ISOURCESHAREDPTR_H_
#define _MEDIAGAPS_IO_ISOURCESHAREDPTR_H_

#include "MediaGaps/IO/ISource.h"
#include "MediaGaps/ISharedPtr.h"

namespace MediaGaps
{
	namespace IO
	{
		class MEDIAGAPS_EXPORTS_KEYWORD SourceSharedPtr : public ISharedPtr<ISource, SourceSharedPtr>
		{
			struct Impl;
			Impl* _impl;

		public:
			SourceSharedPtr();

			explicit SourceSharedPtr(ISource* sample);

			SourceSharedPtr(const SourceSharedPtr& other);

			virtual SourceSharedPtr& operator=(const SourceSharedPtr& other);

			virtual bool operator==(const SourceSharedPtr& other);

			~SourceSharedPtr();

			virtual ISource* Get() const;

			virtual ISource* operator->() const;

			virtual ISource& operator*() const;

			virtual void Reset();

			virtual void Reset(ISource* sample);
		};
	}
}

#endif // _MEDIAGAPS_IO_ISOURCESHAREDPTR_H_
