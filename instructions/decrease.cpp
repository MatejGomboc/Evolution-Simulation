#include "decrease.h"

Decrease::Decrease(unsigned input_pointer, unsigned output_pointer) :
    m_input_pointer(input_pointer),
    m_output_pointer(output_pointer)
{
}

void Decrease::operator()(std::vector<float>& memory, unsigned& subprogram_pointer, std::vector<unsigned>& instruction_pointers, unsigned& return_pointer) const
{
    (void)return_pointer;
    memory[m_output_pointer] = memory[m_input_pointer] - 1;
    instruction_pointers[subprogram_pointer]++;
}
