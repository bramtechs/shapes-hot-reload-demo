#include "shape_factory.hh"
#include "circle_shape.hh"
#include "color_resolver.hh"
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
    std::unordered_map<std::string, std::function<IShape*(Color)>> builders {
        { "Rectangle", std::bind(&ShapeFactory::createRectangle, this, std::placeholders::_1) },
        { "Circle", std::bind(&ShapeFactory::createCircle, this, std::placeholders::_1) }
    };

    try {
        Color color = resolveColor();
        return std::unique_ptr<IShape>(builders.at(mShapeType)(color));
    } catch (const std::exception& ex) {
        throw ShapeBuilderError(std::format("Could not parse shape {}: {}", mShapeType, ex.what()));
    }
}

RectangleShape* ShapeFactory::createRectangle(Color color) const
{
    int x = std::stoi(mConfig.at("x"));
    int y = std::stoi(mConfig.at("y"));
    int width = std::stoi(mConfig.at("width"));
    int height = std::stoi(mConfig.at("height"));
    return new RectangleShape(x, y, width, height, color);
}

CircleShape* ShapeFactory::createCircle(Color color) const
{
    int x = std::stoi(mConfig.at("x"));
    int y = std::stoi(mConfig.at("y"));
    int radius = std::stoi(mConfig.at("radius"));
    return new CircleShape(x, y, radius, color);
}

Color ShapeFactory::resolveColor() const
{
    if (mConfig.find("color") == mConfig.end()) {
        return RED;
    }

    const auto colorName = mConfig.at("color");
    if (auto color = ColorResolver::resolve(colorName); color.has_value()) {
        return color.value();
    }

    throw ShapeBuilderError(std::format("Invalid color: {}", colorName));
}

}
