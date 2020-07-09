#ifndef _MEDIAGAPS_MEDIA_IWRITER_H_
#define _MEDIAGAPS_MEDIA_IWRITER_H_

#include "MediaGaps/Media/IActionWithState.h"
#include "MediaGaps/Media/IBaseWriter.h"

namespace MediaGaps
{
    namespace Media
    {
        class MEDIAGAPS_EXPORTS_KEYWORD IWriter : public IBaseWriter, public IActionWithState
        {
        public:
            virtual ~IWriter();
        };
    }
}

#endif //_MEDIAGAPS_MEDIA_IWRITER_H_
