#ifndef UTILS_H
#define UTILS_H

#include <string>

namespace Utils
{
    float clamp(float value);
    bool stringToUnsignedShort(const std::string& str, unsigned short& res);
    bool stringToFloat(const std::string& str, float& res);
    bool stringToUnsignedChar(const std::string& str, unsigned char& res);
};

#endif // UTILS_H
