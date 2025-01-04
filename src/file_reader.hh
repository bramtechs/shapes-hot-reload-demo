#pragma once
#include "data_buffer.hh"

#include <string>

namespace demo {

class DataBuffer;
class IFileReader {
public:
    virtual ~IFileReader() = default;

    virtual DataBuffer readFile(const std::string& filePath) = 0;

    virtual std::size_t getFileUpdateTime(const std::string& filePath) = 0;

    virtual bool checkFileExists(const std::string& fileName) = 0;

};

}
