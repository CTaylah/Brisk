#include "Log.h"

namespace Brisk

{
    std::shared_ptr<spdlog::logger> Log::s_logger; 
    
    void Log::init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");

        s_logger = spdlog::stdout_color_mt("BRISK");
        s_logger->set_level(spdlog::level::trace);

    }
    
} 
