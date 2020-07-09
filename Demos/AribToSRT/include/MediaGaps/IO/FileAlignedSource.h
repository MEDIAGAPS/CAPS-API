#ifndef _MEDIAGAPS_IO_FILEALIGNEDSOURCE_H_
#define _MEDIAGAPS_IO_FILEALIGNEDSOURCE_H_

#include "MediaGaps/IO/IBoundedSource.h"

namespace MediaGaps
{
namespace IO
{
	class MEDIAGAPS_EXPORTS_KEYWORD FileAlignedSource : public IBoundedSource
	{
		struct Impl;
		Impl* _impl;

	public:
		explicit FileAlignedSource (const WChar* fileName, UInt64 bufferSize = 2 * 1024 * 1024);

		~FileAlignedSource ();

		UInt64 GetAbsoluteOffset () const;

		UInt64 Read (unsigned char* buffer, UInt64 size);

		void SkipData(UInt64 amountData);

		void Seek (UInt64 position);

		bool HasFinished () const;

		UInt64 GetRemainingData() const override;

		UInt64 GetSize() const override;
	};
}
}

#endif //_MEDIAGAPS_IO_FILEALIGNEDSOURCE_H_
