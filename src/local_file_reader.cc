#include "local_file_reader.hh"
#include "data_buffer.hh"
#include "formatted_error.hh"

#include <filesystem>
#include <fstream>

namespace observer {

DataBuffer LocalFileReader::readFile(const std::string& filePath)
{
    std::ifstream file(filePath, std::ios::binary);
    if (!file.is_open()) {
        throw formatted_error("Failed to open file: {}", filePath.c_str());
    }
    file.seekg(0, std::ios::end);
    std::streampos size = file.tellg();
    file.seekg(0, std::ios::beg);

    DataBuffer buffer(size);
    file.read(buffer.data(), size);
    return buffer;
}

std::size_t LocalFileReader::getFileUpdateTime(const std::string& filePath)
{
    const auto fsPath = std::filesystem::path(filePath);
    return std::filesystem::last_write_time(fsPath).time_since_epoch().count();
}

bool LocalFileReader::checkFileExists(const std::string& filePath)
{
    return std::filesystem::exists(filePath);
}

bool LocalFileReader::hasFileUpdated(const std::string& filePath)
{
    if (mLastWriteTimes.find(filePath) == mLastWriteTimes.end()) {
        // check if the file hasn't been tracked yet
        auto updateTime = getFileUpdateTime(filePath);
        if (updateTime != mLastWriteTimes.at(filePath)) {
            mLastWriteTimes[filePath] = updateTime;
            return true;
        }
    }
    return true;
}

}
