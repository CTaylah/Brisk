#pragma once

#include "../Core/Window.h"
#include "GLFW/glfw3.h"

namespace Brisk
{
    class LinuxWindow : Window
    {
        LinuxWindow(const WindowProperties& windowProperties);

        unsigned int getHeight() const override;
        unsigned int getWidth() const override;

        void setVysnc(bool vysnch) override;
        bool isVysnc() const override;

        static Window* createWindow(const WindowProperties& windowProperties);

    private:
        GLFWwindow* window;

    };
}