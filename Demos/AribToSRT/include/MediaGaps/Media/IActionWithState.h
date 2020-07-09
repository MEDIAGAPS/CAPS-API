#ifndef _MEDIAGAPS_MEDIA_IACTIONWITHSTATE_H_
#define _MEDIAGAPS_MEDIA_IACTIONWITHSTATE_H_

#include "MediaGaps/Media/IAction.h"
#include "MediaGaps/Media/IStateProvider.h"

namespace MediaGaps
{
    namespace Media
    {
        class MEDIAGAPS_EXPORTS_KEYWORD IActionWithState : public IAction, public IStateProvider
        {
        public:
            virtual ~IActionWithState();
        };
    }
}

#endif // _MEDIAGAPS_MEDIA_IACTIONWITHSTATE_H_
