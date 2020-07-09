#ifndef _MEDIAGAPS_IO_SINKNAMELISTENER_H_
#define _MEDIAGAPS_IO_SINKNAMELISTENER_H_

#include "MediaGaps/Exports.h"

namespace MediaGaps
{
namespace IO
{
    /** Listener class for new sink names.
     */
    class MEDIAGAPS_EXPORTS_KEYWORD SinkNameListener
    {
    public:
        enum Kind
        {
            Kind_Unknown = 0,
            Kind_Video,
            Kind_Audio,
            Kind_Data,
            Kind_Compound,
            Kind_Reference,
            Kind_Manifest,
			Kind_Pattern,
			Kind_AAF
        };

        virtual ~SinkNameListener ();

        virtual void SinkNameNew (const char* name, Kind kind) = 0;

        virtual void SinkNameFinished () = 0;
    };
}
}

#endif //_MEDIAGAPS_IO_SINKNAMELISTENER_H_