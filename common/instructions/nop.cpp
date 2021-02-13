#include "nop.h"

const std::string Nop::MNEMONIC = "NOP";

void Nop::operator()(std::vector<int32_t>& memory, uint8_t& subprogram_index,
    std::vector<uint16_t>& instruction_addresses, std::vector<uint8_t>& return_indices) const
{
    (void)memory;
    (void)return_indices;
    instruction_addresses[subprogram_index]++;
}

std::vector<std::string> Nop::toStringTokens() const
{
    return std::vector<std::string>{ MNEMONIC };
}

std::unique_ptr<Instruction> Nop::fromStringTokens(const std::vector<std::string>& tokens)
{
    if (tokens.size() != 1) {
        return nullptr;
    }

    if (tokens[0] != MNEMONIC) {
        return nullptr;
    }

    return std::make_unique<Nop>();
}

std::vector<uint8_t> Nop::toByteArray() const
{
    std::vector<uint8_t> array;
    array.push_back(static_cast<uint8_t>(Id::NOP));
    return array;
}

std::unique_ptr<Instruction> Nop::fromByteArray(const std::vector<uint8_t>& array, size_t& offset)
{
    if (array.size() - offset < sizeof(uint8_t)) {
        return nullptr;
    }

    if (array[offset++] != static_cast<uint8_t>(Id::NOP)) {
        return nullptr;
    }

    return std::make_unique<Nop>();
}
