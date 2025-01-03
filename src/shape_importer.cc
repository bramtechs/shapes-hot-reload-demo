#include "shape_importer.hh"

namespace demo {

ShapeImporter::ShapeImporter(const std::string& filePath)
    : mFilePath(filePath)
    , mState(std::make_unique<ShapeImporterClosedState>(*this))
{
}

void ShapeImporter::open()
{
    return mState->open();
}

void ShapeImporter::close()
{
    return mState->close();
}

std::vector<std::unique_ptr<IShape>> ShapeImporter::readShapes()
{
    return mState->readShapes();
}

void ShapeImporter::setState(std::unique_ptr<IShapeImporterState>&& state)
{
    mState = std::move(state);
}

}
