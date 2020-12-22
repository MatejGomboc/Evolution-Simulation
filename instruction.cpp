#include <limits>
#include "instruction.h"

Instruction::~Instruction() = default;

std::unique_ptr<Instruction> Instruction::fromStringTokens(const std::vector<std::string>& tokens)
{
}

float Instruction::clamp(float value)
{
    if (value == std::numeric_limits<float>::infinity()) {
        return std::numeric_limits<float>::max();
    } else if (value == -std::numeric_limits<float>::infinity()) {
        return -std::numeric_limits<float>::max();
    } else {
        return value;
    }
}
