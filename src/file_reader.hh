/*
 * Copyright (c) 2025. Doomhowl Interactive - All Rights Reserved
 * Redistribution and use in source and binary forms, with or without modification are not permitted
 * without the prior written permission of Doomhowl Interactive.
 *
 * File created on: 03-01-2025
 */

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
