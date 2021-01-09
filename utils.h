#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <cstdint>

namespace Utils
{
    float clamp(float value);
    bool stringToUnsignedShort(const std::string& str, uint16_t& res);
    bool stringToFloat(const std::string& str, float& res);
    bool stringToUnsignedChar(const std::string& str, uint8_t& res);
};

#endif // UTILS_H
