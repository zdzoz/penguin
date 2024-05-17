#pragma once

#include "../window.h"
#define GLFW_EXPOSE_NATIVE_COCOA
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

namespace pn {

class OsxWindow : public Window {
public:
    OsxWindow(Window::Props&& props);
    ~OsxWindow() override;

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
