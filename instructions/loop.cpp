#include "loop.h"

Loop::Loop(unsigned subprogram_pointer) :
    m_subprogram_pointer(subprogram_pointer)
{
}

void Loop::operator()(std::vector<float>& memory, unsigned& subprogram_pointer, std::vector<unsigned>& instruction_pointers, unsigned& return_pointer) const
{
    (void)memory;
    (void)return_pointer;

    instruction_pointers[subprogram_pointer]++;
    return_pointer = subprogram_pointer;

    subprogram_pointer = m_subprogram_pointer;
    instruction_pointers[m_subprogram_pointer] = 0;
}
