#ifndef _MEDIAGAPS_ISHAREDPTR_H_
#define _MEDIAGAPS_ISHAREDPTR_H_

#include "MediaGaps/Exports.h"

namespace MediaGaps
{
    template <typename TYPE, typename BASECLASS>
    class MEDIAGAPS_EXPORTS_KEYWORD ISharedPtr
    {
    public:

		virtual ~ISharedPtr() = default;

        virtual BASECLASS& operator=(const BASECLASS& other) = 0;

		virtual TYPE* operator->() const = 0;

		virtual TYPE& operator*() const = 0;

        virtual TYPE* Get() const = 0;

        virtual void Reset() = 0;

        virtual void Reset(TYPE* sample) = 0;
    };
}

#endif //_MEDIAGAPS_ISHAREDPTR_H_
