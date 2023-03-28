#pragma once
#include "Keys.h"
#include "Window.h"

#include "glm/glm.hpp"

namespace Brisk{

    class Input
    {
    public:
        static void setWindow(Window* window) 
        { 
            s_window = window->getGlfwWindow(); 
        }

        static bool isKeyPressed(unsigned int key) 
        { 
            return glfwGetKey(s_window, key) == GLFW_PRESS;
        }    

        static glm::dvec2 getMousePosition()
        {
            glm::dvec2 pos(1.0);
            glfwGetCursorPos(s_window, &pos.x, &pos.y);
            return pos;
        }
        


    private:
        static GLFWwindow* s_window;

    };

    inline GLFWwindow* Input::s_window;

}