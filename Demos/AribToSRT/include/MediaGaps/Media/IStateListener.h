#ifndef _MEDIAGAPS_MEDIA_ISTATELISTENER_H_
#define _MEDIAGAPS_MEDIA_ISTATELISTENER_H_

#include "MediaGaps/IErrorInfoProvider.h"

namespace MediaGaps
{
    namespace Media
    {
        class MEDIAGAPS_EXPORTS_KEYWORD IStateListener
        {
        public:
            virtual ~IStateListener();

            virtual void StateChanged() = 0;
        };
    }
}

#endif // _MEDIAGAPS_MEDIA_ISTATELISTENER_H_
