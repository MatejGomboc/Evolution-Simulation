#include "or.h"

Or::Or(unsigned short input1_pointer, unsigned short input2_pointer, unsigned short output_pointer) :
    m_input1_pointer(input1_pointer),
    m_input2_pointer(input2_pointer),
    m_output_pointer(output_pointer)
{
}

void Or::operator()(std::vector<float>& memory, unsigned short& subprogram_pointer, std::vector<unsigned short>& instruction_pointers, unsigned short& return_pointer) const
{
    (void)return_pointer;
    memory[m_output_pointer] = (memory[m_input1_pointer] || memory[m_input2_pointer]);
    instruction_pointers[subprogram_pointer]++;
}
