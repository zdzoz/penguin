#pragma once

#include "window/window.h"

namespace pn {
class App {
private:
    std::unique_ptr<Window> mWindow;

public:
    App();
    App(const char* title, int width, int height);
    App(Window::Props&& props);

    void init(Window::Props&& props);
    void run();
    void destroy();
};
}
