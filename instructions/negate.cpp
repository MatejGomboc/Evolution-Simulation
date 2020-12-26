#include "negate.h"

const std::string Negate::MNEMONIC = "NEG";

Negate::Negate(unsigned short input_pointer, unsigned short output_pointer) :
    m_input_pointer(input_pointer),
    m_output_pointer(output_pointer)
{
}

void Negate::operator()(std::vector<float>& memory, unsigned char& subprogram_pointer,
    std::vector<unsigned short>& instruction_pointers, std::vector<unsigned char>& return_pointers) const
{
    (void)return_pointers;
    memory[m_output_pointer] = (-1) * memory[m_input_pointer];
    instruction_pointers[subprogram_pointer]++;
}

std::vector<std::string> Negate::toStringTokens() const
{
    return std::vector<std::string>{MNEMONIC, std::to_string(m_input_pointer), std::to_string(m_output_pointer)};
}
