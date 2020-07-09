#ifndef _MEDIAGAPS_IEERORINFOPROVIDER_H_
#define _MEDIAGAPS_IEERORINFOPROVIDER_H_

#include "MediaGaps/IErrorListener.h"
#include "MediaGaps/Exception.h"

namespace MediaGaps
{
    /** Provides error information
    */
    class MEDIAGAPS_EXPORTS_KEYWORD IErrorInfoProvider
    {
    public:
        virtual ~IErrorInfoProvider();

        /** Returns the defined error code.
        * \return if no error existed, returns "ExceptionCode_None", otherwise returns the error code.
        */
        virtual ExceptionCode GetErrorCode() const = 0;

        /** Returns the system error message.
        * \return a string with system error message
        */
        virtual const char* GetErrorMsg() const = 0;

        virtual void SetErrorListener(IErrorListener* listener) = 0;
    };
}

#endif // _MEDIAGAPS_IEERORINFOPROVIDER_H_
