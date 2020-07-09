#ifndef _MEDIAGAPS_LOGGING_FILELOGGER_H_
#define _MEDIAGAPS_LOGGING_FILELOGGER_H_

#include "MediaGaps/Logging/LoggerWriter.h"

namespace MediaGaps
{
    namespace Logging
    {
        /** Class for output logs into a file.
        */
        class MEDIAGAPS_EXPORTS_KEYWORD FileLoggerWriter : public LoggerWriter
        {
            struct Impl;
            Impl* _impl;

        public:
            explicit FileLoggerWriter(const wchar_t* filename, LoggingLevel minLogLevel = LoggingLevel_Info);

            ~FileLoggerWriter();

            void Log(LoggingLevel level, const char* msg) override;
        };
    }
}

#endif //_MEDIAGAPS_LOGGING_FILELOGGER_H_
