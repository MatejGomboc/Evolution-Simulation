#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <cstring>
#include <cstdint>
#include <vector>
#include <random>

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

    template <typename T>
    T parseByteArray(const std::vector<uint8_t>& bytes, size_t& offset)
    {
        T value;
        std::memcpy(&value, bytes.data() + offset, sizeof(T));
        offset += sizeof(T);
        return value;
    }

    bool generateRandomBool();
    size_t generateRandomInt(size_t min, size_t max);
    float generateRandomFloat(float min = -std::numeric_limits<float>::max(), float max = std::numeric_limits<float>::max());
};

#endif // UTILS_H
