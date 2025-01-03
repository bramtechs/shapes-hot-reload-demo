#pragma once

namespace demo {

class IShape {
public:
    virtual ~IShape() = default;

    virtual void draw() = 0;
};


}
