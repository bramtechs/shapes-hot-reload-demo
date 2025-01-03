#pragma once
#include "shape.hh"

namespace demo
{

class CircleShape final : public IShape {
public:
    void draw() override;
};

}
