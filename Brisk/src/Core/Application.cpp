
#include "Input.h"
#include "Application.h"

namespace Brisk{

    Application::Application()
    {
        initializeGlfw();

        m_window = new Window();
        Input::setWindow(m_window);    


        if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            Log::error("GLAD failed to initialize");
        }

        glEnable(GL_DEPTH_TEST);

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
            Log::error("GLFW failed to initialize");
            glfwTerminate();
            return;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwSwapInterval(0);

    }
}