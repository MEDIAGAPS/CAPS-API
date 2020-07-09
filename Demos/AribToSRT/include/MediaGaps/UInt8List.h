#ifndef _MEDIAGAPS_UINT8LIST_H_
#define _MEDIAGAPS_UINT8LIST_H_

#include "MediaGaps/IList.h"
#include "MediaGaps/Types.h"

namespace MediaGaps
{
	class MEDIAGAPS_EXPORTS_KEYWORD UInt8List : public IList<UInt8>
	{
		struct Impl;
		Impl* _impl;

	public:
		UInt8List();

		UInt8List(const UInt8List& other);

		UInt8List& operator=(const UInt8List& other);

		~UInt8List();

		void Add(UInt8 item) override;

		void Remove(UInt8 item) override;

		void Pop() override;		

		void Resize(size_t size) override;

		const UInt8& operator[](size_t i) const override;

		UInt8& operator[](size_t i) override;

		size_t GetListSize() const override;

		IListConstIterator ConstBegin() const override;

		IListConstIterator ConstEnd() const override;

		IListIterator Begin() override;

		IListIterator End() override;
	};
}

#endif // _MEDIAGAPS_UINT8LIST_H_
