#ifndef _MEDIAGAPS_MEMORY_ALIGNEDDATA_H_
#define _MEDIAGAPS_MEMORY_ALIGNEDDATA_H_

#include "MediaGaps/Types.h"
#include "MediaGaps/Exports.h"

namespace MediaGaps
{
	namespace Memory
	{
		enum
		{
			DEFAULT_BUFFER_ALIGNMENT_DATA_SIZE = 16
		};

		class MEDIAGAPS_EXPORTS_KEYWORD AlignedData
		{
			struct Impl;
			Impl* _impl;

		protected:

			unsigned char* GetAlignedBufferConst() const;

			unsigned char* GetAlignedBuffer();

			UInt64 GetAlignedAllocatedSize() const;

			size_t GetAlignedAlignment() const;

			explicit AlignedData(UInt64 allocatedSize, size_t alignment = DEFAULT_BUFFER_ALIGNMENT_DATA_SIZE);

			AlignedData(const AlignedData& other);

		public:
			virtual ~AlignedData();
		};
	}
}

#endif //_MEDIAGAPS_MEMORY_ALIGNEDDATA_H_
