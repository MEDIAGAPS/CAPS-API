#ifndef _MEDIAGAPS_TS_PESDATALIST_H_
#define _MEDIAGAPS_TS_PESDATALIST_H_

#include "MediaGaps/IList.h"
#include "MediaGaps/Ts/PesData.h"

namespace MediaGaps
{
	namespace Ts
	{
		class MEDIAGAPS_EXPORTS_KEYWORD PesDataList : public IList<PesData>
		{
			struct Impl;
			Impl* _impl;

		public:
			PesDataList();

			PesDataList(const PesDataList& other);

			PesDataList& operator=(const PesDataList& other);

			~PesDataList();

			void Add(PesData item) override;

			void Remove(PesData item) override;

			void Pop() override;

			void Resize(size_t size) override;

			const PesData& operator[](size_t i) const override;

			PesData& operator[](size_t i) override;

			size_t GetListSize() const override;

			IListConstIterator ConstBegin() const override;

			IListConstIterator ConstEnd() const override;

			IListIterator Begin() override;

			IListIterator End() override;
		};
	}
}

#endif // _MEDIAGAPS_TS_PESDATALIST_H_
