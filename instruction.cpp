#include <limits>
#include "instruction.h"
#include "add.h"
#include "and.h"
#include "condition.h"
#include "copy.h"
#include "decrease.h"
#include "divide.h"
#include "equal.h"
#include "greater.h"
#include "increase.h"
#include "init.h"
#include "loop.h"
#include "multiply.h"
#include "negate.h"
#include "nop.h"
#include "not.h"
#include "or_.h"
#include "return.h"
#include "smaller.h"
#include "subtract.h"

Instruction::~Instruction() = default;

std::unique_ptr<Instruction> Instruction::fromStringTokens(const std::vector<std::string>& tokens)
{
    if (tokens.size() < 1) {
        return nullptr;
    }

    auto it = FACTORIES_TABLE.find(tokens[0]);
    if (it == FACTORIES_TABLE.end()) {
        return nullptr;
    }

    return it->second(tokens);
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

const std::unordered_map<std::string, Instruction::fromStringTokensSpecific_t> Instruction::FACTORIES_TABLE = {
    { Add::MNEMONIC, Add::fromStringTokens },
    { And::MNEMONIC, And::fromStringTokens },
    { Condition::MNEMONIC, Condition::fromStringTokens },
    { Copy::MNEMONIC, Copy::fromStringTokens },
    { Decrease::MNEMONIC, Decrease::fromStringTokens },
    { Divide::MNEMONIC, Divide::fromStringTokens },
    { Equal::MNEMONIC, Equal::fromStringTokens },
    { Greater::MNEMONIC, Greater::fromStringTokens },
    { Increase::MNEMONIC, Increase::fromStringTokens },
    { Init::MNEMONIC, Init::fromStringTokens },
    { Loop::MNEMONIC, Loop::fromStringTokens },
    { Multiply::MNEMONIC, Multiply::fromStringTokens },
    { Negate::MNEMONIC, Negate::fromStringTokens },
    { Nop::MNEMONIC, Nop::fromStringTokens },
    { Not::MNEMONIC, Not::fromStringTokens },
    { Or::MNEMONIC, Or::fromStringTokens },
    { Return::MNEMONIC, Return::fromStringTokens },
    { Smaller::MNEMONIC, Smaller::fromStringTokens },
    { Subtract::MNEMONIC, Subtract::fromStringTokens }
};
