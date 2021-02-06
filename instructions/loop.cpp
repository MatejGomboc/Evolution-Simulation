#include "loop.h"
#include "utils.h"

const std::string Loop::MNEMONIC = "LOP";

Loop::Loop(uint8_t subprogram_pointer) :
    m_subprogram_pointer(subprogram_pointer)
{
}

void Loop::operator()(std::vector<float>& memory, uint8_t& subprogram_pointer,
    std::vector<uint16_t>& instruction_pointers, std::vector<uint8_t>& return_pointers) const
{
    (void)memory;
    (void)return_pointers;

    instruction_pointers[subprogram_pointer]++;
    return_pointers.push_back(subprogram_pointer);

    subprogram_pointer = m_subprogram_pointer;
    instruction_pointers[m_subprogram_pointer] = 0;
}

std::vector<std::string> Loop::toStringTokens() const
{
    return std::vector<std::string>{ MNEMONIC, std::to_string(m_subprogram_pointer) };
}

std::unique_ptr<Instruction> Loop::fromStringTokens(const std::vector<std::string>& tokens)
{
    if (tokens.size() != 2) {
        return nullptr;
    }

    if (tokens[0] != MNEMONIC) {
        return nullptr;
    }

    uint8_t subprogram_pointer;
    if (!Utils::stringToUnsignedChar(tokens[1], subprogram_pointer)) {
        return nullptr;
    }

    return std::make_unique<Loop>(subprogram_pointer);
}

std::vector<uint8_t> Loop::toByteArray() const
{
    std::vector<uint8_t> array;
    array.push_back(static_cast<uint8_t>(Id::LOOP));
    Utils::insertByteArray(array, m_subprogram_pointer);
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

    uint8_t subprogram_pointer = Utils::parseByteArray<uint8_t>(array, offset);

    return std::make_unique<Loop>(subprogram_pointer);
}
