#pragma once

#include "shape_importer.hh"
#include "shape_importer_error.hh"
#include "shape_importer_state.hh"

#include <ini.h>

namespace demo {

ShapeImporterOpenState::ShapeImporterOpenState(ShapeImporter& importer)
    : mImporter(importer)
{
}

void ShapeImporterOpenState::open()
{
    throw ShapeImporterError("ShapeImporter already opened the file");
}

void ShapeImporterOpenState::close()
{
    mImporter.setState(std::make_unique<ShapeImporterClosedState>(mImporter));
}

std::vector<std::unique_ptr<IShape>> ShapeImporterOpenState::readShapes()
{
    throw std::runtime_error("not implemented");
}

}
