#include "window/window.h"

int main()
{
    pn::Window::Props props = {};
    auto win = pn::Window::create(std::move(props));

    if (win) {
        while ((*win)->open()) {
            (*win)->poll();
        }
    }

    return 0;
}
