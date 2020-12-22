#include <limits>
#include "instruction.h"

Instruction::~Instruction() = default;

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
