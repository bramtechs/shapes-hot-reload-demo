#include "rectangle_shape.hh"

#include <raylib.h>

namespace demo {

RectangleShape::RectangleShape()
    : mX(0)
    , mY(0)
    , mWidth(0)
    , mHeight(0)
    , mColor(RED)
{
}

RectangleShape::RectangleShape(int x, int y, int width, int height, Color color)
    : mX(x)
    , mY(y)
    , mWidth(width)
    , mHeight(height)
    , mColor(color)
{
}

void RectangleShape::draw()
{
    DrawRectangle(mX, mY, mWidth, mHeight, mColor);
}

}
