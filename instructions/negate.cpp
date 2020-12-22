#include "negate.h"

Negate::Negate(unsigned input_pointer, unsigned output_pointer) :
    m_input_pointer(input_pointer),
    m_output_pointer(output_pointer)
{
}

void Negate::operator()(std::vector<float>& memory, unsigned& subprogram_pointer, std::vector<unsigned>& instruction_pointers, unsigned& return_pointer) const
{
    (void)return_pointer;
    memory[m_output_pointer] = (-1) * memory[m_input_pointer];
    instruction_pointers[subprogram_pointer]++;
}
