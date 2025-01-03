#pragma once
#include "shape.hh"

#include <memory>
#include <vector>

namespace demo {

class IShapeImporterState {
public:
    virtual ~IShapeImporterState() = default;

    virtual void open() = 0;

    virtual void close() = 0;

    virtual std::vector<std::unique_ptr<IShape>> readShapes() = 0;
};

class ShapeImporter;
class ShapeImporterOpenState final : public IShapeImporterState {
public:
    ShapeImporterOpenState(ShapeImporter& importer);

    void open() override;

    void close() override;

    std::vector<std::unique_ptr<IShape>> readShapes() override;

private:
    ShapeImporter& mImporter;
};

class ShapeImporterClosedState final : public IShapeImporterState {
public:
    ShapeImporterClosedState(ShapeImporter& importer);

    void open() override;

    void close() override;

    std::vector<std::unique_ptr<IShape>> readShapes() override;

private:
    ShapeImporter& mImporter;
};

}
