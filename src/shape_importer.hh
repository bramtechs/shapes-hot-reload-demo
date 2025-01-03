#pragma once
#include "shape_importer_state.hh"

#include <memory>
#include <string>
#include <vector>

namespace demo {

class ShapeImporter final {
public:
    ShapeImporter(const std::string& filePath);

    void open();

    void close();

    std::vector<std::unique_ptr<IShape>> readShapes();

    // TODO: should not be public. learn how C++ 'friends' work
    // https://en.cppreference.com/w/cpp/language/friend
    void setState(std::unique_ptr<IShapeImporterState>&& state);

private:
    std::string mFilePath;
    std::unique_ptr<IShapeImporterState> mState;
};

}
