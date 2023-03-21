#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include <memory>
namespace Brisk
{
    class Log
    {
    public:
        Log();

       std::shared_ptr<spdlog::logger>& getCoreLogger() {return s_coreLogger;} 
       std::shared_ptr<spdlog::logger>& getClientLogger() {return s_clientLogger;} 

    private:
        std::shared_ptr<spdlog::logger> s_coreLogger; 
        std::shared_ptr<spdlog::logger> s_clientLogger; 

    };
    
} 
