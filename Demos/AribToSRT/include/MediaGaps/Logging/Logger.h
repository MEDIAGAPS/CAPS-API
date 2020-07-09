#ifndef _MEDIAGAPS_LOGGER_H_
#define _MEDIAGAPS_LOGGER_H_

#include "MediaGaps/Exports.h"
#include "MediaGaps/NonCopyable.h"

namespace MediaGaps
{
    namespace Logging
    {
        enum LoggingLevel
        {
            LoggingLevel_Debug = 0,
            LoggingLevel_Info,
            LoggingLevel_Warning,
            LoggingLevel_Error,
        };

        class LoggerWriter;

        /** Class for handling logging messages.
          */
        class MEDIAGAPS_EXPORTS_KEYWORD Logger : public NonCopyable
        {
            struct Impl;
            Impl* _impl;

            Logger();

        public:
            ~Logger();

            static Logger& Instance();

            void InstallLoggerWriter(LoggerWriter* loggerWriter) const;
            void UninstallLoggerWriter(LoggerWriter* loggerWriter) const;

            void Debug(const char* msg) const;
            void Info(const char* msg) const;
            void Warning(const char* msg) const;
            void Error(const char* msg) const;
        };
    }
}

#endif //_MEDIAGAPS_LOGGER_H_
