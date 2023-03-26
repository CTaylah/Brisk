#pragma once

#include "Event/Event.h"
#include "Event/KeyboardEvent.h"
#include "Event/MouseEvent.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <string>
#include <vector>

namespace Brisk
{

    struct WindowProperties
    {
        std::string title = "Brisk Engine";
        unsigned int width = 1280;
        unsigned int height = 720;
        bool isVsync = false;
    };

    class Window
    {

    public:
        Window();

        ~Window() = default;
        unsigned int getWidth() { return m_properties.width; }
        unsigned int getHeight() { return m_properties.height; }

        void swapBuffers();

        void onUpdate();
        
        //void setEventcallback(const EventCallbackFn& callback) = 0
        void setVysnc (bool vysnch) {};
        bool isVysnc() { return m_properties.isVsync; }
        GLFWwindow* getGlfwWindow() { return m_window; }

    private:
        GLFWwindow* m_window;
        WindowProperties m_properties;

        std::vector<Event> m_eventList;

        void onEvent();
    
    };


    
} 
