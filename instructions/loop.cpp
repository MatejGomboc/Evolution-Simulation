#include "loop.h"

Loop::Loop(unsigned short subprogram_pointer) :
    m_subprogram_pointer(subprogram_pointer)
{
}

void Loop::operator()(std::vector<float>& memory, unsigned short& subprogram_pointer, std::vector<unsigned short>& instruction_pointers, unsigned short& return_pointer) const
{
    (void)memory;
    (void)return_pointer;

    instruction_pointers[subprogram_pointer]++;
    return_pointer = subprogram_pointer;

    subprogram_pointer = m_subprogram_pointer;
    instruction_pointers[m_subprogram_pointer] = 0;
}
