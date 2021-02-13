#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <cstring>
#include <cstdint>
#include <vector>
#include <random>

namespace Utils
{
    template <typename T>
    bool stringToInt(const std::string& str, T& res, T min, T max)
    {
        int temp;

        try {
            temp = std::stoi(str, nullptr, 0);
        }  catch (...) {
            return false;
        }

        if (temp < min) {
            return false;
        }

        if (temp > max) {
            return false;
        }

        res = static_cast<T>(temp);
        return true;
    }

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
    long long generateRandomInt(long long min, long long max);
};

#endif // UTILS_H
