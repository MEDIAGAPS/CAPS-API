#ifndef _MEDIAGAPS_MEDIA_IPROGRESSINDICATOR_H_
#define _MEDIAGAPS_MEDIA_IPROGRESSINDICATOR_H_

#include "MediaGaps/Exports.h"
#include "MediaGaps/Types.h"

namespace MediaGaps
{
    namespace Media
    {
        class MEDIAGAPS_EXPORTS_KEYWORD IProgressIndicator
        {
        public:
            virtual ~IProgressIndicator();
            virtual UInt64 GetProcessedFrames() const = 0;
        };
    }
}

#endif //_MEDIAGAPS_MEDIA_IPROGRESSINDICATOR_H_
