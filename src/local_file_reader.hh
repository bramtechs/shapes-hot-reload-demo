#pragma once
#include "file_reader.hh"

#include <unordered_map>

namespace observer {

class LocalFileReader final : public IFileReader {
public:
    [[nodiscard]] DataBuffer readFile(const std::string& filePath) override;

    [[nodiscard]] std::size_t getFileUpdateTime(const std::string& filePath) override;

    [[nodiscard]] bool checkFileExists(const std::string& filePath) override;

    [[nodiscard]] bool hasFileUpdated(const std::string& filePath);

private:
    std::unordered_map<std::string, std::size_t> mLastWriteTimes {};
};

}
