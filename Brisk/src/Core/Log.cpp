#include "Log.h"

namespace Brisk
{
    Log::Log()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");
        s_coreLogger = spdlog::stdout_color_mt("ENGINE");
        s_coreLogger->set_level(spdlog::level::trace);

        s_clientLogger = spdlog::stdout_color_mt("CLIENT");
        s_clientLogger->set_level(spdlog::level::trace);

    }



} 
