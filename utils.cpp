#include <limits>
#include "utils.h"

float Utils::clamp(float value)
{
    if (value == std::numeric_limits<float>::infinity()) {
        return std::numeric_limits<float>::max();
    } else if (value == -std::numeric_limits<float>::infinity()) {
        return -std::numeric_limits<float>::max();
    } else {
        return value;
    }
}

bool Utils::stringToUnsignedShort(const std::string& str, unsigned short& res)
{
    int temp;

    try {
        temp = std::stoi(str, nullptr, 0);
    }  catch (...) {
        return false;
    }

    if (temp < 0) {
        return false;
    }

    if (temp > std::numeric_limits<unsigned short>::max()) {
        return false;
    }

    res = static_cast<unsigned short>(temp);
    return true;
}

bool Utils::stringToFloat(const std::string& str, float& res)
{
    float temp;

    try {
        temp = std::stof(str);
    }  catch (...) {
        return false;
    }

    if (!
        ((temp <= std::numeric_limits<float>::max()) || (temp >= -std::numeric_limits<float>::max()))
    ) {
        return false;
    }

    res = temp;
    return true;
}

bool Utils::stringToUnsignedChar(const std::string& str, unsigned char& res)
{
    int temp;

    try {
        temp = std::stoi(str, nullptr, 0);
    }  catch (...) {
        return false;
    }

    if (temp < 0) {
        return false;
    }

    if (temp > std::numeric_limits<unsigned char>::max()) {
        return false;
    }

    res = static_cast<unsigned char>(temp);
    return true;
}
