#pragma once

#include <string>
//Interface for creating Windows. Needs to be implemented per-platform
namespace Brisk
{
    struct WindowProperties
    {
        std::string title = "Brisk Engine";
        unsigned int width = 1280;
        unsigned int height = 720;
        bool isVsync;
    };

    class Window
    {
        public:
        virtual ~Window();
        virtual unsigned int getWidth() const = 0;
        virtual unsigned int getHeight() const = 0;
        
        //virtual void setEventcallback(const EventCallbackFn& callback) = 0
        virtual void setVysnc (bool vysnch) = 0;
        virtual bool isVysnc() const = 0;

        static Window* createWindow(const WindowProperties& windowProperteries);

    };


    
} // namespace Brisk
