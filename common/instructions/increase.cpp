#include "increase.h"
#include "utils.h"

const std::string Increase::MNEMONIC = "INC";

Increase::Increase(uint16_t input_memory_address, uint16_t output_memory_address) :
    m_input_address(input_memory_address),
    m_output_address(output_memory_address)
{
}

void Increase::operator()(std::vector<int32_t>& memory, uint8_t& subprogram_index,
    std::vector<uint16_t>& instruction_addresses, std::vector<uint8_t>& return_indices) const
{
    (void)return_indices;
    memory[m_output_address] = memory[m_input_address] + 1;
    instruction_addresses[subprogram_index]++;
}

std::vector<std::string> Increase::toStringTokens() const
{
    return std::vector<std::string>{ MNEMONIC, std::to_string(m_input_address), std::to_string(m_output_address) };
}

std::unique_ptr<Instruction> Increase::fromStringTokens(const std::vector<std::string>& tokens)
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

    uint16_t output_memory_address;
    if (!Utils::stringToInt<uint16_t>(tokens[2], output_memory_address, 0, std::numeric_limits<uint16_t>::max())) {
        return nullptr;
    }

    return std::make_unique<Increase>(input_memory_address, output_memory_address);
}

std::vector<uint8_t> Increase::toByteArray() const
{
    std::vector<uint8_t> array;
    array.push_back(static_cast<uint8_t>(Id::INCREASE));
    Utils::insertByteArray(array, m_input_address);
    Utils::insertByteArray(array, m_output_address);
    return array;
}

std::unique_ptr<Instruction> Increase::fromByteArray(const std::vector<uint8_t>& array, size_t& offset)
{
    if (array.size() - offset < sizeof(uint8_t) + sizeof(uint16_t) * 2) {
        return nullptr;
    }

    if (array[offset++] != static_cast<uint8_t>(Id::INCREASE)) {
        return nullptr;
    }

    uint16_t input_memory_address = Utils::parseByteArray<uint16_t>(array, offset);
    uint16_t output_memory_address = Utils::parseByteArray<uint16_t>(array, offset);

    return std::make_unique<Increase>(input_memory_address, output_memory_address);
}
