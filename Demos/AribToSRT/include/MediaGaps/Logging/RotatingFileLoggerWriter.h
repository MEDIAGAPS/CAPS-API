#ifndef _MEDIAGAPS_LOGGING_ROTATINGFILELOGGER_H_
#define _MEDIAGAPS_LOGGING_ROTATINGFILELOGGER_H_

#include "MediaGaps/Logging/LoggerWriter.h"
#include "MediaGaps/Types.h"

namespace MediaGaps
{
    namespace Logging
    {
        /** Implementation for rotating logger
          */
        class MEDIAGAPS_EXPORTS_KEYWORD RotatingFileLoggerWriter : public LoggerWriter
        {
            struct Impl;
            Impl* _impl;

        public:
            RotatingFileLoggerWriter(const wchar_t* filename,
                                     UInt32 maxFileSizeInBytes,
                                     UInt32 maxFileCount,
                                     LoggingLevel minLogLevel = LoggingLevel_Info);

            virtual ~RotatingFileLoggerWriter();

            void Log(LoggingLevel level, const char* msg) override;
        };
    }
}

#endif //_MEDIAGAPS_LOGGING_ROTATINGFILELOGGER_H_
