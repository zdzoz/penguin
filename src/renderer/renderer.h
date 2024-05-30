#pragma once

namespace pn {

class Renderer {
public:
    virtual ~Renderer() = default;

    virtual void draw() const = 0;
};
}