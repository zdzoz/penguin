#include "app.h"

int main()
{
    auto app = pn::App();
    app.run();
    app.destroy();

    return 0;
}
