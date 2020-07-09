#ifndef _MEDIAGAPS_TS_PROGRAMDATALIST_H_
#define _MEDIAGAPS_TS_PROGRAMDATALIST_H_

#include "MediaGaps/IList.h"
#include "MediaGaps/Ts/ProgramData.h"

namespace MediaGaps
{
	namespace Ts
	{
		class MEDIAGAPS_EXPORTS_KEYWORD ProgramDataList : public IList<ProgramData>
		{
			struct Impl;
			Impl* _impl;

		public:
			ProgramDataList();
			ProgramDataList(const ProgramDataList& other);
			ProgramDataList& operator=(const ProgramDataList& other);

			~ProgramDataList();

			void Add(ProgramData item) override;
			void Remove(ProgramData item) override;

			void Pop() override;
			void Resize(size_t size) override;

			const ProgramData& operator[](size_t i) const override;
			ProgramData& operator[](size_t i) override;
			size_t GetListSize() const override;

			IListConstIterator ConstBegin() const override;
			IListConstIterator ConstEnd() const override;
			IListIterator Begin() override;
			IListIterator End() override;
		};
	}
}

#endif // _MEDIAGAPS_TS_PROGRAMDATALIST_H_
