#include "formatted_error.hh"
#include "shape_factory.hh"
#include "shape_importer.hh"
#include "shape_importer_error.hh"
#include "shape_importer_state.hh"

#include <fstream>
#include <iostream>
#include <multini.hh>
#include <sstream>
#include <vector>

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
    const auto filePath = mImporter.getFilePath();
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw formatted_error("Failed to open config file at: %s\n", filePath.c_str());
    }

    std::stringstream ss;
    ss << file.rdbuf();
    std::string fileContent = ss.str();

    multini::INIReader reader(fileContent);
    if (reader.hasErrors()) {
        std::cerr << "INI config parse errors:\n"
                  << reader.errors() << '\n';
    }

    std::vector<std::unique_ptr<IShape>> shapes;
    shapes.reserve(reader.size());

    for (const auto& [header, content] : reader) {
        try {
            shapes.emplace_back(ShapeFactory(header, content).buildShape());
        } catch (const ShapeBuilderError& ex) {
            std::cerr << ex.what() << '\n';
        }
    }

    return shapes;
}

}
