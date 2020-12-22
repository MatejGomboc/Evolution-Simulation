#include "not.h"

Not::Not(unsigned input_pointer, unsigned output_pointer) :
    m_input_pointer(input_pointer),
    m_output_pointer(output_pointer)
{
}

void Not::operator()(std::vector<float>& memory, unsigned& subprogram_pointer, std::vector<unsigned>& instruction_pointers) const
{
    memory[m_output_pointer] = !memory[m_input_pointer];
    instruction_pointers[subprogram_pointer]++;
}
