#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <vector>
#include <memory>
#include <string>
#include <cstdint>

class Instruction
{
public:
    enum class Id : uint8_t {
        ADD = 0,
        AND = 1,
        CONDITION = 2,
        COPY = 3,
        DECREASE = 4,
        DIVIDE = 5,
        EQUAL = 6,
        GREATER = 7,
        INCREASE = 8,
        INIT = 9,
        LOOP = 10,
        MULTIPLY = 11,
        NEGATE = 12,
        NOP = 13,
        NOT = 14,
        OR = 15,
        RETURN = 16,
        SMALLER = 17,
        SUBTRACT = 18
    };

    virtual ~Instruction() = 0;
    static std::unique_ptr<Instruction> fromStringTokens(const std::vector<std::string>& tokens);
    static std::unique_ptr<Instruction> fromByteArray(const std::vector<uint8_t>& array, size_t& offset);
    virtual void operator()(std::vector<int32_t>& memory, uint8_t& subprogram_index,
        std::vector<uint16_t>& instruction_addresses, std::vector<uint8_t>& return_indices) const = 0;
    virtual std::vector<std::string> toStringTokens() const = 0;
    virtual std::vector<uint8_t> toByteArray() const = 0;
};

#endif // INSTRUCTION_H
