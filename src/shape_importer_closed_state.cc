#include "shape_importer.hh"
#include "shape_importer_error.hh"
#include "shape_importer_state.hh"

namespace demo {

ShapeImporterClosedState::ShapeImporterClosedState(ShapeImporter& importer)
    : mImporter(importer)
{
}

void ShapeImporterClosedState::open()
{
    mImporter.setState(std::make_unique<ShapeImporterOpenState>(mImporter));
}

void ShapeImporterClosedState::close()
{
    throw ShapeImporterError("ShapeImporter has no file open");
}

std::vector<std::unique_ptr<IShape>> ShapeImporterClosedState::readShapes()
{
    throw ShapeImporterError("ShapeImporter has no file open");
}

}
