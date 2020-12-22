#include "condition.h"

Condition::Condition(unsigned input_pointer, unsigned subprogram_pointer) :
    m_input_pointer(input_pointer),
    m_subprogram_pointer(subprogram_pointer)
{
}

void Condition::operator()(std::vector<float>& memory, unsigned& subprogram_pointer, std::vector<unsigned>& instruction_pointers, unsigned& return_pointer) const
{
    instruction_pointers[subprogram_pointer]++;

    if (memory[m_input_pointer] > 0) {
        return_pointer = subprogram_pointer;
        subprogram_pointer = m_subprogram_pointer;
        instruction_pointers[m_subprogram_pointer] = 0;
    }
}
