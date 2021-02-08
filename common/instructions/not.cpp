#include "not.h"
#include "utils.h"

const std::string Not::MNEMONIC = "NOT";

Not::Not(uint16_t input_memory_address, uint16_t output_memory_address) :
    m_input_address(input_memory_address),
    m_output_address(output_memory_address)
{
}

void Not::operator()(std::vector<float>& memory, uint8_t& subprogram_index,
    std::vector<uint16_t>& instruction_addresses, std::vector<uint8_t>& return_indices) const
{
    (void)return_indices;
    memory[m_output_address] = !memory[m_input_address];
    instruction_addresses[subprogram_index]++;
}

std::vector<std::string> Not::toStringTokens() const
{
    return std::vector<std::string>{ MNEMONIC, std::to_string(m_input_address), std::to_string(m_output_address) };
}

std::unique_ptr<Instruction> Not::fromStringTokens(const std::vector<std::string>& tokens)
{
    if (tokens.size() != 3) {
        return nullptr;
    }

    if (tokens[0] != MNEMONIC) {
        return nullptr;
    }

    uint16_t input_memory_address;
    if (!Utils::stringToUnsignedShort(tokens[1], input_memory_address)) {
        return nullptr;
    }

    uint16_t output_memory_address;
    if (!Utils::stringToUnsignedShort(tokens[2], output_memory_address)) {
        return nullptr;
    }

    return std::make_unique<Not>(input_memory_address, output_memory_address);
}

std::vector<uint8_t> Not::toByteArray() const
{
    std::vector<uint8_t> array;
    array.push_back(static_cast<uint8_t>(Id::NOT));
    Utils::insertByteArray(array, m_input_address);
    Utils::insertByteArray(array, m_output_address);
    return array;
}

std::unique_ptr<Instruction> Not::fromByteArray(const std::vector<uint8_t>& array, size_t& offset)
{
    if (array.size() - offset < sizeof(uint8_t) + sizeof(uint16_t) * 2) {
        return nullptr;
    }

    if (array[offset++] != static_cast<uint8_t>(Id::NOT)) {
        return nullptr;
    }

    uint16_t input_memory_address = Utils::parseByteArray<uint16_t>(array, offset);
    uint16_t output_memory_address = Utils::parseByteArray<uint16_t>(array, offset);

    return std::make_unique<Not>(input_memory_address, output_memory_address);
}
