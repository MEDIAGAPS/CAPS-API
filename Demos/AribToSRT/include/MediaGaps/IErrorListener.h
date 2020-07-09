#ifndef _MEDIAGAPS_IERRORLISTENER_H_
#define _MEDIAGAPS_IERRORLISTENER_H_

#include "MediaGaps/Exports.h"
#include "MediaGaps/Types.h"

namespace MediaGaps
{
    class MEDIAGAPS_EXPORTS_KEYWORD IErrorListener
    {
    public:
        virtual ~IErrorListener();

        virtual void ErrorOccurred(ExceptionCode code, const char* message) = 0;
    };
}

#endif //_MEDIAGAPS_IERRORLISTENER_H_
