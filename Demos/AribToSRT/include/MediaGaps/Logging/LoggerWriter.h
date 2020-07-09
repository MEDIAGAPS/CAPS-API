#ifndef _MEDIAGAPS_LOGGERWRITER_H_
#define _MEDIAGAPS_LOGGERWRITER_H_

#include "MediaGaps/Exports.h"
#include "MediaGaps/Logging/Logger.h"

namespace MediaGaps
{
    namespace Logging
    {
        /** Class for handling logs
          */
        class MEDIAGAPS_EXPORTS_KEYWORD LoggerWriter
        {
        public:
            virtual ~LoggerWriter();

            /** Method that receives the logs.
              * \param level the level for the current message
              * \param msg the message of the current log
              */
            virtual void Log(LoggingLevel level, const char* msg) = 0;
        };

        /** Installs a given logging writer.
          * \param loggerWriter a pointer to a logger writer. If 0 is passed, no logging will be made.
          * Important Note: The lifetime of the writer must be assured until the end of the process, or being deactivated.
          */
        MEDIAGAPS_EXPORTS_KEYWORD void InstallLoggerWriter(LoggerWriter* loggerWriter);

        /** Uninstall a given logging writer.
          * \param loggerWriter a pointer to a logger writer. If 0 is passed, no logging will be made.
          */
        MEDIAGAPS_EXPORTS_KEYWORD void UninstallLoggerWriter(LoggerWriter* loggerWriter);
    }
}

#endif //_MEDIAGAPS_LOGGERWRITER_H_
