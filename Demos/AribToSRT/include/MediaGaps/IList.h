#ifndef _MEDIAGAPS_ILIST_H_
#define _MEDIAGAPS_ILIST_H_

#include "MediaGaps/ExceptionHandler.h"

namespace MediaGaps
{
    template <typename TYPE>
    class IList
    {
    public:
        class IListConstIterator
        {
            const IList<TYPE>& _base;
            size_t _index = 0;

        public:
            IListConstIterator(const IListConstIterator& other)
                : _base(other._base),
                  _index(other._index) { }

            IListConstIterator& operator=(const IListConstIterator& other)
            {
                ExceptionHandler::EnforceMediaGapsException(&_base == &other._base, ExceptionCode_InvalidState, "Trying to assign different classes iterator");
                //_base = other._base;
                _index = other._index;
                return *this;
            }

            explicit IListConstIterator(const IList<TYPE>& base, size_t index)
                : _base(base),
                  _index(index) {}

            const TYPE& operator*() const
            {
                return _base[_index];
            }

            IListConstIterator& operator++()
            {
                ++_index;
                return *this;
            }

            bool operator!=(const IListConstIterator& item) const
            {
                if (&_base != &item._base) return true;
                return _index != item._index;
            }
        };

        class IListIterator
        {
            IList<TYPE>& _base;
            size_t _index = 0;

        public:
            IListIterator(const IListIterator& other)
                : _base(other._base),
                  _index(other._index) { }

            explicit IListIterator(IList<TYPE>& base, size_t index)
                : _base(base),
                  _index(index) {}

            TYPE& operator*()
            {
                return _base[_index];
            }

            IListIterator& operator++()
            {
                ++_index;
                return *this;
            }

            bool operator!=(const IListIterator& item) const
            {
                if (&_base != &item._base) return true;
                return _index != item._index;
            }
        };

        virtual ~IList() = default;

        virtual void Add(TYPE item) = 0;
        virtual void Remove(TYPE item) = 0;

		virtual void Pop()  = 0;
		virtual void Resize(size_t size) = 0;
    	
        virtual const TYPE& operator[](size_t i) const = 0;
        virtual TYPE& operator[](size_t i) = 0;
        virtual size_t GetListSize() const = 0;

        virtual IListConstIterator ConstBegin() const = 0;
        virtual IListConstIterator ConstEnd() const = 0;
        virtual IListIterator Begin() = 0;
        virtual IListIterator End() = 0;
    };
}

#endif // _MEDIAGAPS_ILIST_H_
