#ifndef _MEDIAGAPS_EXCEPTION_HANDLER_H_
#define _MEDIAGAPS_EXCEPTION_HANDLER_H_

#include "MediaGaps/Exports.h"
#include "MediaGaps/Types.h"

namespace MediaGaps
{
    class MEDIAGAPS_EXPORTS_KEYWORD ExceptionHandler
    {
    public:
        static void ThrowMediaGapsException(ExceptionCode code, const char* message);

        static void EnforceMediaGapsException(bool condition, ExceptionCode code, const char* message);
    };
}

#endif // _MEDIAGAPS_EXCEPTION_HANDLER_H_
