#pragma once
#include <functional>
#include <map>
#include <memory>
#include <raylib.h>
#include <stdexcept>
#include <string>

namespace demo {

class IShape;
class RectangleShape;
class CircleShape;

class ShapeBuilderError : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

using ShapeINIEntry = std::map<std::string, std::string>;
class ShapeFactory final {
public:
    ShapeFactory(const std::string& shapeType, const ShapeINIEntry& config);

    std::unique_ptr<IShape> buildShape() const;

private:
    RectangleShape* createRectangle(Color color) const;
    CircleShape* createCircle(Color color) const;

    Color resolveColor() const;

    std::string mShapeType;
    const ShapeINIEntry& mConfig;
};

}
