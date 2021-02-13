#include "multiply.h"
#include "utils.h"

const std::string Multiply::MNEMONIC = "MUL";

Multiply::Multiply(uint16_t input1_memory_address, uint16_t input2_memory_address, uint16_t output_memory_address) :
    m_input1_memory_address(input1_memory_address),
    m_input2_memory_address(input2_memory_address),
    m_output_address(output_memory_address)
{
}

void Multiply::operator()(std::vector<int32_t>& memory, uint8_t& subprogram_index,
    std::vector<uint16_t>& instruction_addresses, std::vector<uint8_t>& return_indices) const
{
    (void)return_indices;
    memory[m_output_address] = memory[m_input1_memory_address] * memory[m_input2_memory_address];
    instruction_addresses[subprogram_index]++;
}

std::vector<std::string> Multiply::toStringTokens() const
{
    return std::vector<std::string>{ MNEMONIC, std::to_string(m_input1_memory_address), std::to_string(m_input2_memory_address), std::to_string(m_output_address) };
}

std::unique_ptr<Instruction> Multiply::fromStringTokens(const std::vector<std::string>& tokens)
{
    if (tokens.size() != 4) {
        return nullptr;
    }

    if (tokens[0] != MNEMONIC) {
        return nullptr;
    }

    uint16_t input1_memory_address;
    if (!Utils::stringToInt<uint16_t>(tokens[1], input1_memory_address, 0, std::numeric_limits<uint16_t>::max())) {
        return nullptr;
    }

    uint16_t input2_memory_address;
    if (!Utils::stringToInt<uint16_t>(tokens[2], input2_memory_address, 0, std::numeric_limits<uint16_t>::max())) {
        return nullptr;
    }

    uint16_t output_memory_address;
    if (!Utils::stringToInt<uint16_t>(tokens[3], output_memory_address, 0, std::numeric_limits<uint16_t>::max())) {
        return nullptr;
    }

    return std::make_unique<Multiply>(input1_memory_address, input2_memory_address, output_memory_address);
}

std::vector<uint8_t> Multiply::toByteArray() const
{
    std::vector<uint8_t> array;
    array.push_back(static_cast<uint8_t>(Id::MULTIPLY));
    Utils::insertByteArray(array, m_input1_memory_address);
    Utils::insertByteArray(array, m_input2_memory_address);
    Utils::insertByteArray(array, m_output_address);
    return array;
}

std::unique_ptr<Instruction> Multiply::fromByteArray(const std::vector<uint8_t>& array, size_t& offset)
{
    if (array.size() - offset < sizeof(uint8_t) + sizeof(uint16_t) * 3) {
        return nullptr;
    }

    if (array[offset++] != static_cast<uint8_t>(Id::MULTIPLY)) {
        return nullptr;
    }

    uint16_t input1_memory_address = Utils::parseByteArray<uint16_t>(array, offset);
    uint16_t input2_memory_address = Utils::parseByteArray<uint16_t>(array, offset);
    uint16_t output_memory_address = Utils::parseByteArray<uint16_t>(array, offset);

    return std::make_unique<Multiply>(input1_memory_address, input2_memory_address, output_memory_address);
}
