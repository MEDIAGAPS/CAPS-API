#ifndef _MEDIAGAPS_LOGGING_CONSOLELOGGER_H_
#define _MEDIAGAPS_LOGGING_CONSOLELOGGER_H_

#include "MediaGaps/Logging/LoggerWriter.h"

namespace MediaGaps
{
    namespace Logging
    {
        /** Class for logging to standard output
          */
        class MEDIAGAPS_EXPORTS_KEYWORD ConsoleLoggerWriter : public LoggerWriter
        {
            struct Impl;
            Impl* _impl;

        public:
            explicit ConsoleLoggerWriter(LoggingLevel minLogLevel = LoggingLevel_Info);

            ~ConsoleLoggerWriter();

            void Log(LoggingLevel level, const char* msg) override;
        };
    }
}

#endif //_MEDIAGAPS_LOGGING_CONSOLELOGGER_H_
