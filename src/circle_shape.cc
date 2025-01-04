#include "circle_shape.hh"

namespace demo {

CircleShape::CircleShape(int x, int y, int radius, Color color)
    : mX(x)
    , mY(y)
    , mRadius(radius)
    , mColor(color)
{
}

void CircleShape::draw()
{
    DrawCircle(mX, mY, mRadius, mColor);
}

}
