#include <limits>
#include <unordered_map>
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
    static const std::unordered_map<std::string,
        std::unique_ptr<Instruction>(*)(const std::vector<std::string>& tokens)> FACTORIES_TABLE = {
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

    if (tokens.size() < 1) {
        return nullptr;
    }

    auto it = FACTORIES_TABLE.find(tokens[0]);
    if (it == FACTORIES_TABLE.end()) {
        return nullptr;
    }

    return it->second(tokens);
}

std::unique_ptr<Instruction> Instruction::fromByteArray(const std::vector<uint8_t>& array, size_t& offset)
{
    static const std::unordered_map<uint8_t,
        std::unique_ptr<Instruction>(*)(const std::vector<uint8_t>& array, size_t& offset)> FACTORIES_TABLE = {
        { static_cast<uint8_t>(Id::ADD), Add::fromByteArray },
        { static_cast<uint8_t>(Id::AND), And::fromByteArray },
        { static_cast<uint8_t>(Id::CONDITION), Condition::fromByteArray },
        { static_cast<uint8_t>(Id::COPY), Copy::fromByteArray },
        { static_cast<uint8_t>(Id::DECREASE), Decrease::fromByteArray },
        { static_cast<uint8_t>(Id::DIVIDE), Divide::fromByteArray },
        { static_cast<uint8_t>(Id::EQUAL), Equal::fromByteArray },
        { static_cast<uint8_t>(Id::GREATER), Greater::fromByteArray },
        { static_cast<uint8_t>(Id::INCREASE), Increase::fromByteArray },
        { static_cast<uint8_t>(Id::INIT), Init::fromByteArray },
        { static_cast<uint8_t>(Id::LOOP), Loop::fromByteArray },
        { static_cast<uint8_t>(Id::MULTIPLY), Multiply::fromByteArray },
        { static_cast<uint8_t>(Id::NEGATE), Negate::fromByteArray },
        { static_cast<uint8_t>(Id::NOP), Nop::fromByteArray },
        { static_cast<uint8_t>(Id::NOT), Not::fromByteArray },
        { static_cast<uint8_t>(Id::OR), Or::fromByteArray },
        { static_cast<uint8_t>(Id::RETURN), Return::fromByteArray },
        { static_cast<uint8_t>(Id::SMALLER), Smaller::fromByteArray },
        { static_cast<uint8_t>(Id::SUBTRACT), Subtract::fromByteArray }
    };

    if (array.size() - offset < 1) {
        return nullptr;
    }

    auto it = FACTORIES_TABLE.find(array[0]);
    if (it == FACTORIES_TABLE.end()) {
        return nullptr;
    }

    return it->second(array, offset);
}
