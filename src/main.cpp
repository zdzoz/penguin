#include <fmt/core.h>
#include <GLFW/glfw3.h>

int main() {
    glfwInit();

    fmt::println("hello world!");

    glfwTerminate();
    return 0;
}
