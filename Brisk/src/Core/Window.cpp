#include "Window.h"
#include "Log.h"



namespace Brisk
{

    void keyCallback (GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        if(key == GLFW_KEY_E && action == GLFW_PRESS)
        {
           EventHandler::getEventList()->push_back(KeyboardEvent(GLFW_KEY_E));
           int x = EventHandler::getEventList()->at(0).getEventType();
            Log::warn(x);
        }
    }

  
    void mouseCallback(GLFWwindow* window, double xpos, double ypos)
    {
        EventHandler::getEventList()->push_back(MouseEvent(xpos, ypos));
        Log::warn(xpos);

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

} 

