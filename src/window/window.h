#pragma once

namespace pn {

class Window {
public:
    struct Props {
        const char* title { "Penguin" };
        int width { 800 }, height { 600 };
        bool resizable { true };
    };

    // this needs to be a singleton
    static std::optional<std::unique_ptr<Window>> create(Props&& props);

    virtual ~Window() = default;

    virtual bool open() const = 0;
    virtual void poll() const = 0;

    virtual int width() const = 0;
    virtual int height() const = 0;

    virtual const void* get() const = 0;

    virtual void setResizable(bool resizable) = 0;
    virtual bool isResizable() const = 0;

protected:
    Window() = default;

private:
    Window(Window&) = delete;
    Window& operator=(Window&) = delete;
};

}
