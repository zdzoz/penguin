#pragma once

#include "../window.h"
#include <GLFW/glfw3.h>

namespace pn {

    class Win32Window : public Window {
    public:
        Win32Window(Window::Props&& props);
        ~Win32Window() override;

        bool open() const override;
        void poll() const override;

        int width() const override;
        int height() const override;

        const void* get() const override;

        void setResizable(bool resizable) override;
        bool isResizable() const override;
    private:
        Window::Props _props;
        GLFWwindow* _window;
        void* _native_window;

        static bool initialized;
    };

}