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
        ADD,
        AND,
        CONDITION,
        COPY,
        DECREASE,
        DIVIDE,
        EQUAL,
        GREATER,
        INCREASE,
        INIT,
        LOOP,
        MULTIPLY,
        NEGATE,
        NOP,
        NOT,
        OR,
        RETURN,
        SMALLER,
        SUBTRACT
    };

    virtual ~Instruction() = 0;
    static std::unique_ptr<Instruction> fromStringTokens(const std::vector<std::string>& tokens);
    virtual void operator()(std::vector<float>& memory, uint8_t& subprogram_pointer,
        std::vector<uint16_t>& instruction_pointers, std::vector<uint8_t>& return_pointers) const = 0;
    virtual std::vector<std::string> toStringTokens() const = 0;
    virtual std::vector<uint8_t> toByteArray() const = 0;
};

#endif // INSTRUCTION_H
