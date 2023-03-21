#pragma once

#include "Log.h"
namespace Brisk
{
    class Application
    {
        public:
            Application();
            //This class will be subclassed by the sandbox application
            virtual ~Application();

            void run();

        protected:
            Brisk::Log logger;
    };
}
