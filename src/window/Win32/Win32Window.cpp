#include "Win32Window.h"

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
        return std::make_unique<Win32Window>(std::move(props));
    }

    Win32Window::Win32Window(Window::Props&& props)
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

        _native_window = nullptr;
    }

    Win32Window::~Win32Window()
    {
        glfwDestroyWindow(_window);
        glfwTerminate();
    }

    bool Win32Window::open() const
    {
        return !glfwWindowShouldClose(_window);
    }

    void Win32Window::poll() const
    {
        glfwSwapBuffers(_window);
        glfwPollEvents();
    }

    int Win32Window::width() const { return _props.width; }
    int Win32Window::height() const { return _props.height; }

    const void* Win32Window::get() const { return _native_window; }

    void Win32Window::setResizable(bool resizable)
    {
        throw std::runtime_error(fmt::format("TODO: implement {}", __func__));
    }

    bool Win32Window::isResizable() const
    {
        throw std::runtime_error(fmt::format("TODO: implement {}", __func__));
    }

}