#pragma once

#include "Log.h"
#include "Window.h"
#include "Renderer/Renderer.h"

#include "glad/glad.h"
#include  "GLFW/glfw3.h"

namespace Brisk
{
        
    class Application
    {
        public:
            Application();
            //This class will be subclassed by the sandbox application
            virtual ~Application();

            void run();

        private:
            void initializeGlfw();


        protected:
            Brisk::Log logger;
            Window* m_window;
            Renderer m_renderer;
    };
}
