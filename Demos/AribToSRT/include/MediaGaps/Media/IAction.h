#ifndef _MEDIAGAPS_MEDIA_IACTION_H_
#define _MEDIAGAPS_MEDIA_IACTION_H_

#include "MediaGaps/Exports.h"

namespace MediaGaps
{
    namespace Media
    {
        class MEDIAGAPS_EXPORTS_KEYWORD IAction
        {
        public:
            virtual ~IAction();

            virtual void Start() = 0;

            virtual void Abort() = 0;
        };
    }
}

#endif // _MEDIAGAPS_MEDIA_IACTION_H_
