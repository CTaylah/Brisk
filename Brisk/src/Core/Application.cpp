

#include "Application.h"

namespace Brisk{

    Application::Application()
    {
        initializeGlfw();

        m_window = new Window();


        if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            Log::getCoreLogger()->error("GLAD failed to initialize");
        }


    }

    Application::~Application()
    {
        glfwTerminate();
        delete(m_window);
    }

    void Application::run()
    {
        
    }

    void Application::initializeGlfw()
    {

        int success = glfwInit();
        if(GLFW_FALSE == success)
        {
            Log::getCoreLogger()->error("GLFW failed to initialize");
            glfwTerminate();
            return;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    }
}