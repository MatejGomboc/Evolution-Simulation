#include <limits>
#include "divide.h"

const std::string Divide::MNEMONIC = "DIV";

Divide::Divide(unsigned short input1_pointer, unsigned short input2_pointer, unsigned short output_pointer) :
    m_input1_pointer(input1_pointer),
    m_input2_pointer(input2_pointer),
    m_output_pointer(output_pointer)
{
}

void Divide::operator()(std::vector<float>& memory, unsigned char& subprogram_pointer,
    std::vector<unsigned short>& instruction_pointers, std::vector<unsigned char>& return_pointers) const
{
    (void)return_pointers;

    if (memory[m_input2_pointer] == 0) {
        if (memory[m_input1_pointer] == 0) {
            memory[m_output_pointer] = 1;
        } else {
            if (memory[m_input1_pointer] > 0) {
                memory[m_output_pointer] = std::numeric_limits<float>::max();
            } else {
                memory[m_output_pointer] = -std::numeric_limits<float>::max();
            }
        }
    } else {
        memory[m_output_pointer] = memory[m_input1_pointer] / memory[m_input2_pointer];
        memory[m_output_pointer] = clamp(memory[m_output_pointer]);
    }

    instruction_pointers[subprogram_pointer]++;
}

std::vector<std::string> Divide::toStringTokens() const
{
    return std::vector<std::string>{MNEMONIC, std::to_string(m_input1_pointer), std::to_string(m_input2_pointer), std::to_string(m_output_pointer)};
}

std::unique_ptr<Instruction> Divide::fromStringTokens(const std::vector<std::string>& tokens)
{
    if (tokens[0] != MNEMONIC) {
        return nullptr;
    }

    return nullptr;
}
