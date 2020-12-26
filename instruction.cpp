#include <limits>
#include "instruction.h"

Instruction::~Instruction() = default;

std::unique_ptr<Instruction> Instruction::fromStringTokens(const std::vector<std::string>& tokens)
{
    if ((tokens.size() < Instruction::MIN_NUM_TOKENS) || (tokens.size() > Instruction::MAX_NUM_TOKENS)) {
        return nullptr;
    }

    return nullptr;
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
