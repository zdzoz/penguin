#include "app.h"

namespace pn {

App::App() { init({}); }

App::App(const char* title, int width, int height)
{
    Window::Props props = { .title = title, .width = width, .height = height, .resizable = true };
    init(std::move(props));
}

App::App(Window::Props&& props) { init(std::move(props)); }

void App::init(Window::Props&& props)
{
    auto windowOpt = Window::create(std::move(props));
    if (!windowOpt) {
        throw std::runtime_error("failed to create window");
    }
    mWindow = std::move(*windowOpt);
}

void App::run()
{
    if (mWindow) {
        while (mWindow->open()) {
            mWindow->poll();
        }
    }
}

void App::destroy() { }

}
