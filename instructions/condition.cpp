#include "condition.h"

Condition::Condition(unsigned short input_pointer, unsigned short subprogram_pointer) :
    m_input_pointer(input_pointer),
    m_subprogram_pointer(subprogram_pointer)
{
}

void Condition::operator()(std::vector<float>& memory, unsigned short& subprogram_pointer, std::vector<unsigned short>& instruction_pointers, std::vector<unsigned short>& return_pointers) const
{
    instruction_pointers[subprogram_pointer]++;

    if (memory[m_input_pointer] != 0) {
        return_pointers.push_back(subprogram_pointer);
        subprogram_pointer = m_subprogram_pointer;
        instruction_pointers[m_subprogram_pointer] = 0;
    }
}
