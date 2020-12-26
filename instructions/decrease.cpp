#include "decrease.h"

const std::string Decrease::MNEMONIC = "DEC";

Decrease::Decrease(unsigned short input_pointer, unsigned short output_pointer) :
    m_input_pointer(input_pointer),
    m_output_pointer(output_pointer)
{
}

void Decrease::operator()(std::vector<float>& memory, unsigned char& subprogram_pointer,
    std::vector<unsigned short>& instruction_pointers, std::vector<unsigned char>& return_pointers) const
{
    (void)return_pointers;
    memory[m_output_pointer] = memory[m_input_pointer] - 1;
    memory[m_output_pointer] = clamp(memory[m_output_pointer]);
    instruction_pointers[subprogram_pointer]++;
}

std::vector<std::string> Decrease::toStringTokens() const
{
    return std::vector<std::string>{MNEMONIC, std::to_string(m_input_pointer), std::to_string(m_output_pointer)};
}
