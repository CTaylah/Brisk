#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include <memory>

namespace Brisk
{

    class Log
    {
    public:
       static void init();

       static std::shared_ptr<spdlog::logger>& getLogger() {return s_logger;} 

        template<typename... Args >
        static void warn(const Args&... args)
        { s_clientLogger->warn(args...); }

        template<typename... Args >
        static void error(const Args&... args)
        { s_clientLogger->error(args...); }

        template<typename... Args >
        static void info(const Args&... args)
        { s_clientLogger->info(args...); }


    private:
        static std::shared_ptr<spdlog::logger> s_logger; 

    };

    
} 

//#define BR_CORE_TRACE(...) ::Brisk::Log::getCoreLogger()->info(__VA_ARGS__)