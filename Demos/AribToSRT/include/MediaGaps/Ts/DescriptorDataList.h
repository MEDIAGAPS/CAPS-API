#ifndef _MEDIAGAPS_TS_DESCRIPTORDATALIST_H_
#define _MEDIAGAPS_TS_DESCRIPTORDATALIST_H_

#include "MediaGaps/IList.h"
#include "MediaGaps/Ts/DescriptorData.h"

namespace MediaGaps
{
	namespace Ts
	{
		class MEDIAGAPS_EXPORTS_KEYWORD DescriptorDataList : public IList<DescriptorData>
		{
			struct Impl;
			Impl* _impl;

		public:
			DescriptorDataList();

			DescriptorDataList(const DescriptorDataList& other);

			DescriptorDataList& operator=(const DescriptorDataList& other);

			~DescriptorDataList();

			void Add(DescriptorData item) override;

			void Remove(DescriptorData item) override;

			void Pop() override;

			void Resize(size_t size) override;

			const DescriptorData& operator[](size_t i) const override;

			DescriptorData& operator[](size_t i) override;

			size_t GetListSize() const override;

			IListConstIterator ConstBegin() const override;

			IListConstIterator ConstEnd() const override;

			IListIterator Begin() override;

			IListIterator End() override;
		};
	}
}

#endif // _MEDIAGAPS_TS_DESCRIPTORDATALIST_H_
