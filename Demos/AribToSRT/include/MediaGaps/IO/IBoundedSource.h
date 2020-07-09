#ifndef _MEDIAGAPS_IO_IBOUNDEDSOURCE_H_
#define _MEDIAGAPS_IO_IBOUNDEDSOURCE_H_

#include "MediaGaps/Types.h"
#include "MediaGaps/Exports.h"
#include "MediaGaps/IO/ISource.h"

namespace MediaGaps
{
	namespace IO
	{
		class MEDIAGAPS_EXPORTS_KEYWORD IBoundedSource : public ISource
		{
		public:
			virtual ~IBoundedSource();

			virtual UInt64 GetRemainingData() const = 0;

			virtual UInt64 GetSize()  const = 0;

			virtual void Seek(UInt64 position) = 0;
		};
	}
}

#endif // _MEDIAGAPS_IO_IBOUNDEDSOURCE_H_
