#pragma once
#include <cstdio>
#include <stdexcept>

namespace demo
{

class formatted_error final : public std::exception {
public:
    template<typename... Args>
    constexpr formatted_error(const char* fmt, Args&&... args)
    {
        snprintf(mMsgBuffer, sizeof(mMsgBuffer), fmt, std::forward<Args>(args)...);
    }

    const char* what() const noexcept override
    {
        return mMsgBuffer;
    }

private:
    char mMsgBuffer[1024] {};
};

}
