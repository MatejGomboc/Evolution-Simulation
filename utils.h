#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <cstdint>
#include <vector>

namespace Utils
{
    float clamp(float value);
    bool stringToUnsignedShort(const std::string& str, uint16_t& res);
    bool stringToFloat(const std::string& str, float& res);
    bool stringToUnsignedChar(const std::string& str, uint8_t& res);

    template <typename T>
    void insertByteArray(std::vector<uint8_t>& target, T value)
    {
        uint8_t* raw = reinterpret_cast<uint8_t*>(&value);
        target.insert(target.end(), raw, raw + sizeof(T));
    }
};

#endif // UTILS_H
