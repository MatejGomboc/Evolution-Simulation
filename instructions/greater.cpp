#include "greater.h"

const std::string Greater::MNEMONIC = "GRT";

Greater::Greater(unsigned short input1_pointer, unsigned short input2_pointer, unsigned short output_pointer) :
    m_input1_pointer(input1_pointer),
    m_input2_pointer(input2_pointer),
    m_output_pointer(output_pointer)
{
}

void Greater::operator()(std::vector<float>& memory, unsigned char& subprogram_pointer,
    std::vector<unsigned short>& instruction_pointers, std::vector<unsigned char>& return_pointers) const
{
    (void)return_pointers;
    memory[m_output_pointer] = (memory[m_input1_pointer] > memory[m_input2_pointer]);
    instruction_pointers[subprogram_pointer]++;
}

std::vector<std::string> Greater::toStringTokens() const
{
    return std::vector<std::string>{MNEMONIC, std::to_string(m_input1_pointer), std::to_string(m_input2_pointer), std::to_string(m_output_pointer)};
}

std::unique_ptr<Instruction> Greater::fromStringTokens(const std::vector<std::string>& tokens)
{
    if (tokens[0] != MNEMONIC) {
        return nullptr;
    }

    return nullptr;
}
