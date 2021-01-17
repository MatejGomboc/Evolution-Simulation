#include "condition.h"
#include "utils.h"

const std::string Condition::MNEMONIC = "CON";

Condition::Condition(uint16_t input_pointer, uint8_t subprogram_pointer) :
    m_input_pointer(input_pointer),
    m_subprogram_pointer(subprogram_pointer)
{
}

void Condition::operator()(std::vector<float>& memory, uint8_t& subprogram_pointer,
    std::vector<uint16_t>& instruction_pointers, std::vector<uint8_t>& return_pointers) const
{
    instruction_pointers[subprogram_pointer]++;

    if (memory[m_input_pointer] != 0) {
        return_pointers.push_back(subprogram_pointer);
        subprogram_pointer = m_subprogram_pointer;
        instruction_pointers[m_subprogram_pointer] = 0;
    }
}

std::vector<std::string> Condition::toStringTokens() const
{
    return std::vector<std::string>{ MNEMONIC, std::to_string(m_input_pointer), std::to_string(m_subprogram_pointer) };
}

std::unique_ptr<Instruction> Condition::fromStringTokens(const std::vector<std::string>& tokens)
{
    if (tokens.size() != 3) {
        return nullptr;
    }

    if (tokens[0] != MNEMONIC) {
        return nullptr;
    }

    uint16_t input_pointer;
    if (!Utils::stringToUnsignedShort(tokens[1], input_pointer)) {
        return nullptr;
    }

    uint8_t subprogram_pointer;
    if (!Utils::stringToUnsignedChar(tokens[2], subprogram_pointer)) {
        return nullptr;
    }

    return std::make_unique<Condition>(input_pointer, subprogram_pointer);
}

std::vector<uint8_t> Condition::toByteArray() const
{
    std::vector<uint8_t> array;
    array.push_back(static_cast<uint8_t>(Id::CONDITION));
    Utils::insertByteArray(array, m_input_pointer);
    Utils::insertByteArray(array, m_subprogram_pointer);
    return array;
}
