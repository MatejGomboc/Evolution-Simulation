#include "and.h"

And::And(unsigned input1_pointer, unsigned input2_pointer, unsigned output_pointer) :
    m_input1_pointer(input1_pointer),
    m_input2_pointer(input2_pointer),
    m_output_pointer(output_pointer)
{
}

void And::operator()(std::vector<float>& memory, unsigned& subprogram_pointer, std::vector<unsigned>& instruction_pointers) const
{
    memory[m_output_pointer] = (memory[m_input1_pointer] && memory[m_input2_pointer]);
    instruction_pointers[subprogram_pointer]++;
}
