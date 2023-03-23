#include "Window.h"

#include <iostream>

namespace Brisk
{
    Window::Window()
    {
        m_window = glfwCreateWindow(1280, 720, "Brisk", NULL, NULL);
        if(nullptr == m_window)
        {
            std::cout << "Failed to create GLFW  Window Window.cpp:12" << std::endl; 
        } 

        glfwMakeContextCurrent(m_window);
        glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
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

} // namespace Brisk

