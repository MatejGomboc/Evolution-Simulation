#include "init.h"
#include "utils.h"

const std::string Init::MNEMONIC = "INI";

Init::Init(int32_t value, uint16_t address) :
    m_value(value),
    m_address(address)
{
}

void Init::operator()(std::vector<int32_t>& memory, uint8_t& subprogram_index,
    std::vector<uint16_t>& instruction_addresses, std::vector<uint8_t>& return_indices) const
{
    (void)return_indices;
    memory[m_address] = m_value;
    instruction_addresses[subprogram_index]++;
}

std::vector<std::string> Init::toStringTokens() const
{
    return std::vector<std::string>{ MNEMONIC, std::to_string(m_value), std::to_string(m_address) };
}

std::unique_ptr<Instruction> Init::fromStringTokens(const std::vector<std::string>& tokens)
{
    if (tokens.size() != 3) {
        return nullptr;
    }

    if (tokens[0] != MNEMONIC) {
        return nullptr;
    }

    int32_t value;
    if (Utils::stringToInt<int32_t>(tokens[1], value, -std::numeric_limits<int32_t>::max(), std::numeric_limits<int32_t>::max())) {
        return nullptr;
    }

    uint16_t address;
    if (!Utils::stringToInt<uint16_t>(tokens[2], address, 0, std::numeric_limits<uint16_t>::max())) {
        return nullptr;
    }

    return std::make_unique<Init>(value, address);
}

std::vector<uint8_t> Init::toByteArray() const
{
    std::vector<uint8_t> array;
    array.push_back(static_cast<uint8_t>(Id::INIT));
    Utils::insertByteArray(array, m_value);
    Utils::insertByteArray(array, m_address);
    return array;
}

std::unique_ptr<Instruction> Init::fromByteArray(const std::vector<uint8_t>& array, size_t& offset)
{
    if (array.size() - offset < sizeof(uint8_t) + sizeof(int32_t) + sizeof(uint16_t)) {
        return nullptr;
    }

    if (array[offset++] != static_cast<uint8_t>(Id::INIT)) {
        return nullptr;
    }

    int32_t value = Utils::parseByteArray<int32_t>(array, offset);
    uint16_t address = Utils::parseByteArray<uint16_t>(array, offset);

    return std::make_unique<Init>(value, address);
}
