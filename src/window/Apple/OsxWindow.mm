#include "OsxWindow.h"

namespace pn {

// TODO: allow multiple windows
std::optional<std::unique_ptr<Window>> Window::create(Props&& props)
{
    static bool initialized = false;
    if (initialized) {
        // FIX: update to use logger
        fmt::println(stderr, "Warn: window already exists");
        return std::nullopt;
    }

    initialized = true;
    return std::make_unique<OsxWindow>(std::move(props));
}

OsxWindow::OsxWindow(Window::Props&& props)
    : _window(nullptr)
    , _native_window(nullptr)
{
    this->_props = props;

    if (!glfwInit()) {
        throw std::runtime_error("Could not initialize glfw");
    }

    _window = glfwCreateWindow(props.width, props.height, props.title, NULL, NULL);
    if (!_window) {
        glfwTerminate();
        throw std::runtime_error("Could not create window");
    }

    _native_window = (__bridge void*)glfwGetCocoaWindow(_window);
}

OsxWindow::~OsxWindow()
{
    glfwDestroyWindow(_window);
    glfwTerminate();
}

bool OsxWindow::open() const
{
    return !glfwWindowShouldClose(_window);
}

void OsxWindow::poll() const
{
    glfwSwapBuffers(_window);
    glfwPollEvents();
}

int OsxWindow::width() const { return _props.width; }
int OsxWindow::height() const { return _props.height; }

const void* OsxWindow::get() const { return _native_window; }

void OsxWindow::setResizable(bool resizable)
{
    throw std::runtime_error(fmt::format("TODO: implement {}", __func__));
}

bool OsxWindow::isResizable() const
{
    throw std::runtime_error(fmt::format("TODO: implement {}", __func__));
}

}
