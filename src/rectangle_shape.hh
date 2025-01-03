#pragma once
#include "shape.hh"

namespace demo {

class RectangleShape final : public IShape {
public:
    void draw() override;
};

}
