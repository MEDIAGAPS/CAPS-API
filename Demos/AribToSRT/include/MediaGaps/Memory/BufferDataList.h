#ifndef _MEDIAGAPS_MEMORY_IBUFFERDATALIST_H_
#define _MEDIAGAPS_MEMORY_IBUFFERDATALIST_H_

#include "MediaGaps/IList.h"
#include "MediaGaps/Memory/BufferDataSharedPtr.h"

namespace MediaGaps
{
	namespace Memory
	{
		class MEDIAGAPS_EXPORTS_KEYWORD BufferDataList : public IList<BufferDataSharedPtr>
		{
			struct Impl;
			Impl* _impl;
		public:
			BufferDataList();
			BufferDataList(const BufferDataList& other);
			BufferDataList& operator=(const BufferDataList& other);

			virtual ~BufferDataList();

			void Add(BufferDataSharedPtr item) override;
			void Remove(BufferDataSharedPtr item) override;

			void Pop() override;
			void Resize(size_t size) override;

			
			const BufferDataSharedPtr& operator[](size_t i) const override;
			BufferDataSharedPtr& operator[](size_t i) override;
			size_t GetListSize() const override;

			IListConstIterator ConstBegin() const override;
			IListConstIterator ConstEnd() const override;
			IListIterator Begin() override;
			IListIterator End() override;

			/** Pointer to the position where the sample is stored at first element.
			* @throw ExceptionCode_InvalidState when buffer data list is not single dimension 
		   */
			const unsigned char* GetFirstBuffer() const;

			/** Returns the size of the sample at first element
			* @throw ExceptionCode_InvalidState when buffer data list is not single dimension
			*/
			UInt64 GetFirstSize() const ;

			/** Returns the linesize of the sample at first element. If the value is not know returns 0.
			* @throw ExceptionCode_InvalidState when buffer data list is not single dimension
			*/
			UInt64 GetFirstLinesize() const ;

		};
	}
}

#endif //_MEDIAGAPS_MEMORY_IBUFFERDATALIST_H_
