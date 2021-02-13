#include "condition.h"
#include "utils.h"
#include <limits>

const std::string Condition::MNEMONIC = "CON";

Condition::Condition(uint16_t input_memory_address, uint8_t subprogram_index) :
    m_input_address(input_memory_address),
    m_subprogram_index(subprogram_index)
{
}

void Condition::operator()(std::vector<int32_t>& memory, uint8_t& subprogram_index,
    std::vector<uint16_t>& instruction_addresses, std::vector<uint8_t>& return_indices) const
{
    instruction_addresses[subprogram_index]++;

    if (memory[m_input_address] != 0) {
        return_indices.push_back(subprogram_index);
        subprogram_index = m_subprogram_index;
        instruction_addresses[m_subprogram_index] = 0;
    }
}

std::vector<std::string> Condition::toStringTokens() const
{
    return std::vector<std::string>{ MNEMONIC, std::to_string(m_input_address), std::to_string(m_subprogram_index) };
}

std::unique_ptr<Instruction> Condition::fromStringTokens(const std::vector<std::string>& tokens)
{
    if (tokens.size() != 3) {
        return nullptr;
    }

    if (tokens[0] != MNEMONIC) {
        return nullptr;
    }

    uint16_t input_memory_address;
    if (!Utils::stringToInt<uint16_t>(tokens[1], input_memory_address, 0, std::numeric_limits<uint16_t>::max())) {
        return nullptr;
    }

    uint8_t subprogram_index;
    if (!Utils::stringToInt<uint8_t>(tokens[2], subprogram_index, 0, std::numeric_limits<uint8_t>::max())) {
        return nullptr;
    }

    return std::make_unique<Condition>(input_memory_address, subprogram_index);
}

std::vector<uint8_t> Condition::toByteArray() const
{
    std::vector<uint8_t> array;
    array.push_back(static_cast<uint8_t>(Id::CONDITION));
    Utils::insertByteArray(array, m_input_address);
    Utils::insertByteArray(array, m_subprogram_index);
    return array;
}

std::unique_ptr<Instruction> Condition::fromByteArray(const std::vector<uint8_t>& array, size_t& offset)
{
    if (array.size() - offset < sizeof(uint8_t) + sizeof(uint16_t) + sizeof(uint8_t)) {
        return nullptr;
    }

    if (array[offset++] != static_cast<uint8_t>(Id::CONDITION)) {
        return nullptr;
    }

    uint16_t input_memory_address = Utils::parseByteArray<uint16_t>(array, offset);
    uint8_t subprogram_index = Utils::parseByteArray<uint8_t>(array, offset);

    return std::make_unique<Condition>(input_memory_address, subprogram_index);
}
