#pragma once
#include "shape.hh"
#include "utils.hh"

#include <raylib.h>

namespace demo {

class RectangleShape final : public IShape {
public:
    RectangleShape();
    RectangleShape(int x, int y, int width, int height, Color color = RED);

    void draw() override;

private:
    int mX;
    int mY;
    int mWidth;
    int mHeight;
    Color mColor;

public:
    GETTER_SETTER(X)
    GETTER_SETTER(Y)
    GETTER_SETTER(Width)
    GETTER_SETTER(Height)
    GETTER_SETTER(Color)
};

}
