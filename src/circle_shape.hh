#pragma once
#include "shape.hh"
#include "utils.hh"

#include <raylib.h>

namespace demo
{

class CircleShape final : public IShape {
public:
    CircleShape(int x, int y, int radius, Color color = RED);

    void draw() override;

private:
    int mX;
    int mY;
    int mRadius;
    Color mColor;

public:
    GETTER_SETTER(X)
    GETTER_SETTER(Y)
    GETTER_SETTER(Radius)
};

}
