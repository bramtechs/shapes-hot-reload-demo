#pragma once
#include <stdexcept>

namespace demo
{

class ShapeImporterError : public std::runtime_error
{
public:
    using std::runtime_error::runtime_error;
};

}
