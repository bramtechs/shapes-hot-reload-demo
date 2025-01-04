#pragma once
#include <optional>
#include <raylib.h>
#include <string>

namespace demo {

class ColorResolver final {
public:
    static std::optional<Color> resolve(std::string color);

private:
    // utility class
    ColorResolver() = delete;
};

}
