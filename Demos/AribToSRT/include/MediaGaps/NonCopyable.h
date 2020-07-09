#ifndef _MEDIAGAPS_NONCOPYABLE_H_
#define _MEDIAGAPS_NONCOPYABLE_H_

#include "MediaGaps/Exports.h"

namespace MediaGaps
{
    class MEDIAGAPS_EXPORTS_KEYWORD NonCopyable
    {
    protected:
        NonCopyable();
        virtual ~NonCopyable();

    private:
        NonCopyable(const NonCopyable&);
        const NonCopyable& operator=(const NonCopyable&);
    };
}
#endif //_MEDIAGAPS_NONCOPYABLE_H_
