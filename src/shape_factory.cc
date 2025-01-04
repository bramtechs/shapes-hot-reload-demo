#include "shape_factory.hh"
#include "circle_shape.hh"
#include "rectangle_shape.hh"

#include <format>
#include <functional>
#include <unordered_map>

namespace demo {

ShapeFactory::ShapeFactory(const std::string& shapeType, const ShapeINIEntry& config)
    : mShapeType(shapeType)
    , mConfig(config)
{
}

std::unique_ptr<IShape> ShapeFactory::buildShape() const
{
    std::unordered_map<std::string, std::function<IShape*()>> builders {
        { "Rectangle", std::bind(&ShapeFactory::createRectangle, this) },
        { "Circle", std::bind(&ShapeFactory::createCircle, this) }
    };

    try {
        return std::unique_ptr<IShape>(builders.at(mShapeType)());
    } catch (const std::exception& ex) {
        throw ShapeBuilderError(std::format("Could not parse shape {}: {}", mShapeType, ex.what()));
    }
}

RectangleShape* ShapeFactory::createRectangle() const
{
    int x = std::stoi(mConfig.at("x"));
    int y = std::stoi(mConfig.at("y"));
    int width = std::stoi(mConfig.at("width"));
    int height = std::stoi(mConfig.at("height"));
    return new RectangleShape(x, y, width, height);
}

CircleShape* ShapeFactory::createCircle() const
{
    int x = std::stoi(mConfig.at("x"));
    int y = std::stoi(mConfig.at("y"));
    int radius = std::stoi(mConfig.at("radius"));
    return new CircleShape(x, y, radius);
}

}
