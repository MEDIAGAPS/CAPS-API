#include "CustomLoggerAdapter.h"

#include <iostream>

using namespace MediaGaps::Logging;
using namespace MediaGaps;

using namespace MOVCreator;

CustomLoggerAdapter::CustomLoggerAdapter()
{
    Logger::Instance().InstallLoggerWriter(this);    
}

CustomLoggerAdapter::~CustomLoggerAdapter()
{
    Logger::Instance().UninstallLoggerWriter(this);
}

void CustomLoggerAdapter::Log(LoggingLevel level, const char* msg)
{
    if (level == LoggingLevel_Debug) return;

    std::cout << "--> API log: " << msg << std::endl;
}
