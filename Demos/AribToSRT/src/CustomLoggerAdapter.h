#ifndef _CUSTOMLOGGERADAPTER_H_
#define _CUSTOMLOGGERADAPTER_H_

#include "MediaGaps/Logging/LoggerWriter.h"

namespace MOVCreator
{
    /** This shows how you can integrate the internal logging API into your product.
     * If you don't want a customized logging you can use existent classes like ConsoleLoggerWriter or RotatingFileLoggerWriter
     *
     */
    class CustomLoggerAdapter : public MediaGaps::Logging::LoggerWriter
    {
    public:
        CustomLoggerAdapter();
        ~CustomLoggerAdapter();

        void Log(MediaGaps::Logging::LoggingLevel level, const char* msg) override;
    };
}

#endif // _CUSTOMLOGGERADAPTER_H_
