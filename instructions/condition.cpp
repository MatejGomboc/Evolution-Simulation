#include "condition.h"

const std::string Condition::MNEMONIC = "CON";

Condition::Condition(unsigned short input_pointer, unsigned char subprogram_pointer) :
    m_input_pointer(input_pointer),
    m_subprogram_pointer(subprogram_pointer)
{
}

void Condition::operator()(std::vector<float>& memory, unsigned char& subprogram_pointer,
    std::vector<unsigned short>& instruction_pointers, std::vector<unsigned char>& return_pointers) const
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

    unsigned short input_pointer;
    if (!stringToUnsignedShort(tokens[1], input_pointer)) {
        return nullptr;
    }

    unsigned char subprogram_pointer;
    if (!stringToUnsignedChar(tokens[2], subprogram_pointer)) {
        return nullptr;
    }

    return std::make_unique<Condition>(input_pointer, subprogram_pointer);
}
