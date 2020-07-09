#ifndef _MEDIAGAPS_EXCEPTION_H_
#define _MEDIAGAPS_EXCEPTION_H_

#include "MediaGaps/Exports.h"
#include "MediaGaps/Types.h"

namespace MediaGaps
{
    class MEDIAGAPS_EXPORTS_KEYWORD Exception
    {
        struct Impl;
        Impl* _impl;

    public:
        /** Constructor.
          */
        Exception(ExceptionCode code, const char* message);

        /** Copy constructor.
          */
        Exception(const Exception& other);

        /** Assignement operator
          */
        Exception& operator=(const Exception&);

        /** Destructor
          */
        virtual ~Exception();

        /** Human readable message indicating the reason of the exception.
          */
        const char* GetMGExceptionMessage() const;

        /** A code containing the reason of the exception.
          */
        ExceptionCode GetMGExceptionCode() const;
    };
}

#endif // _MEDIAGAPS_EXCEPTION_H_
