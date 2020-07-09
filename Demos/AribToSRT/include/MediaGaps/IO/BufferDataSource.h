#ifndef _MEDIAGAPS_BUFFERDATASOURCE_H_
#define _MEDIAGAPS_BUFFERDATASOURCE_H_

#include "MediaGaps/IO/ISource.h"
#include "MediaGaps/Memory/IBufferData.h"

namespace MediaGaps
{
	namespace IO
	{
		class MEDIAGAPS_EXPORTS_KEYWORD BufferDataSource : public ISource
		{
			struct Impl;
			Impl* _impl;

		public:
			explicit BufferDataSource(Memory::IBufferData& source);

			~BufferDataSource();
			
			UInt64 Read(unsigned char* buffer, UInt64 size) override;

			UInt64 GetAbsoluteOffset() const override;

			bool HasFinished() const override;

			void SkipData(UInt64 amountData) override;

			UInt64 Remaining() const;
		};
	}
}

#endif //_MEDIAGAPS_BUFFERDATASOURCE_H_
