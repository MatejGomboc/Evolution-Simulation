#include "loop.h"
#include "utils.h"

const std::string Loop::MNEMONIC = "LOP";

Loop::Loop(uint8_t subprogram_index) :
    m_subprogram_index(subprogram_index)
{
}

void Loop::operator()(std::vector<int32_t>& memory, uint8_t& subprogram_index,
    std::vector<uint16_t>& instruction_addresses, std::vector<uint8_t>& return_indices) const
{
    (void)memory;
    (void)return_indices;

    instruction_addresses[subprogram_index]++;
    return_indices.push_back(subprogram_index);

    subprogram_index = m_subprogram_index;
    instruction_addresses[m_subprogram_index] = 0;
}

std::vector<std::string> Loop::toStringTokens() const
{
    return std::vector<std::string>{ MNEMONIC, std::to_string(m_subprogram_index) };
}

std::unique_ptr<Instruction> Loop::fromStringTokens(const std::vector<std::string>& tokens)
{
    if (tokens.size() != 2) {
        return nullptr;
    }

    if (tokens[0] != MNEMONIC) {
        return nullptr;
    }

    uint8_t subprogram_index;
    if (!Utils::stringToInt<uint8_t>(tokens[1], subprogram_index, 0, std::numeric_limits<uint8_t>::max())) {
        return nullptr;
    }

    return std::make_unique<Loop>(subprogram_index);
}

std::vector<uint8_t> Loop::toByteArray() const
{
    std::vector<uint8_t> array;
    array.push_back(static_cast<uint8_t>(Id::LOOP));
    Utils::insertByteArray(array, m_subprogram_index);
    return array;
}

std::unique_ptr<Instruction> Loop::fromByteArray(const std::vector<uint8_t>& array, size_t& offset)
{
    if (array.size() - offset < sizeof(uint8_t) + sizeof(uint8_t)) {
        return nullptr;
    }

    if (array[offset++] != static_cast<uint8_t>(Id::LOOP)) {
        return nullptr;
    }

    uint8_t subprogram_index = Utils::parseByteArray<uint8_t>(array, offset);

    return std::make_unique<Loop>(subprogram_index);
}
