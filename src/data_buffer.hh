#pragma once

#include <cassert>
#include <memory>
#include <string>
#include <string_view>
#include <vector>

namespace observer {
/**
 * Shared buffer of raw data.
 */
class DataBuffer final {
public:
    DataBuffer() = default;

    DataBuffer(char* data, size_t sizeInBytes)
        : mBuffer(std::make_shared<std::vector<char>>(reinterpret_cast<char*>(data), reinterpret_cast<char*>(data + sizeInBytes)))
    {
        assert(data != nullptr);
    }

    DataBuffer(const std::string_view& text)
        : mBuffer(std::make_shared<std::vector<char>>(text.begin(), text.end()))
    {
    }

    DataBuffer(const std::string& text)
        : mBuffer(std::make_shared<std::vector<char>>(text.begin(), text.end()))
    {
    }

    DataBuffer(size_t sizeInBytes)
        : mBuffer(std::make_shared<std::vector<char>>(sizeInBytes))
    {
    }

    /**
     * @brief Gets readonly data of the buffer.
     */
    template<typename T = char>
    [[nodiscard]] const T* data() const
    {
        return reinterpret_cast<T*>(mBuffer->data());
    }

    /**
     * @brief Get data of the buffer, allowing writing.
     */
    template<typename T = char>
    [[nodiscard]] T* data()
    {
        return reinterpret_cast<T*>(mBuffer->data());
    }

    [[nodiscard]] size_t size() const
    {
        return mBuffer->size();
    }

    /**
     * @brief Gets the data of the buffer and ensure it is null-terminated.
     */
    [[nodiscard]] const char* str()
    {
        assert(mBuffer != nullptr);
        if (!mBuffer) {
            return nullptr;
        }

        if (mBuffer->empty()) {
            return nullptr;
        }

        // if no null-terminator, add one
        if (mBuffer->back() != '\0') {
            mBuffer->emplace_back('\0');
        }
        return mBuffer->data();
    }

private:
    std::shared_ptr<std::vector<char>> mBuffer {};
};

}
