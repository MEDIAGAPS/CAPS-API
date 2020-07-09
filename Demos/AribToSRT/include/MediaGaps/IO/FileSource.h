#ifndef _MEDIAGAPS_IO_FILESOURCE_H_
#define _MEDIAGAPS_IO_FILESOURCE_H_

#include "MediaGaps/IO/IBoundedSource.h"

namespace MediaGaps
{
	namespace IO
	{
		class MEDIAGAPS_EXPORTS_KEYWORD FileSource : public IBoundedSource
		{
			struct Impl;
			Impl* _impl;

		public:
			explicit FileSource(const WChar* fileName);

			~FileSource();

			virtual UInt64 GetAbsoluteOffset() const;

			virtual UInt64 Read(unsigned char* buffer, UInt64 size);

			virtual UInt64 GetRemainingData() const;

			void SkipData(UInt64 amountData);

			virtual void Seek(UInt64 position);

			void UpdateSize(bool value);

			UInt64 GetSize() const;

			bool HasFinished() const;

		};
	}
}


#endif //_MEDIAGAPS_IO_FILESOURCE_H_
