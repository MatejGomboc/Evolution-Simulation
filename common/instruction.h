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
        CLEAR = 2,
        CONDITION = 3,
        COPY = 4,
        DECREASE = 5,
        DIVIDE = 6,
        EQUAL = 7,
        GREATER = 8,
        INCREASE = 9,
        INIT = 10,
        LOOP = 11,
        MULTIPLY = 12,
        NEGATE = 13,
        NOP = 14,
        NOT = 15,
        OR = 16,
        RETURN = 17,
        SET = 18,
        SMALLER = 19,
        SUBTRACT = 20
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
