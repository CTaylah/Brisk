#pragma once

#include "Log.h"
#include "Window.h"

#include "Event/Event.h"
#include "Renderer/Renderer.h"

#include "glad/glad.h"
#include  "GLFW/glfw3.h"

#include <vector>


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
            Window* m_window;
            Renderer m_renderer;
    };
}
