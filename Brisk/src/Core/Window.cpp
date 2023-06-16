#include "Window.h"
#include "Log.h"



namespace Brisk
{

    void keyCallback (GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        EventHandler::getEventList()->push_back(new KeyboardEvent(key));
    }

  
    void mouseCallback(GLFWwindow* window, double xpos, double ypos)
    {
        EventHandler::getEventList()->push_back(new MouseEvent(xpos, ypos));
    }
    
    void windowSizeCallback(GLFWwindow* window, int width, int height)
    {
        EventHandler::getEventList()->push_back(new WindowResizeEvent(width, height));
    }

    Window::Window()
    {

        m_window = glfwCreateWindow(1280, 720, "Brisk", NULL, NULL);
        if(nullptr == m_window)
        {
            Log::error("Failed to create a GLFW window");
        } 

        glfwMakeContextCurrent(m_window);
        glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        glfwSetKeyCallback(m_window, keyCallback);
        glfwSetCursorPosCallback(m_window, mouseCallback);
        glfwSetWindowSizeCallback(m_window, windowSizeCallback);
    }   


    void Window::swapBuffers()
    {
        glfwSwapBuffers(m_window);
    }

    void Window::onUpdate()
    {
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }


    void Window::setCursorVisibility(bool cursorVisibile)
    {
        if(cursorVisibile)
            glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL); 
        
        else
            glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    }

} 

