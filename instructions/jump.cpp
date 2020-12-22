#include "jump.h"

Jump::Jump(unsigned subprogram_pointer) :
    m_subprogram_pointer(subprogram_pointer)
{
}

void Jump::operator()(std::vector<float>& memory, unsigned& subprogram_pointer, std::vector<unsigned>& instruction_pointers) const
{
    (void)memory;
    instruction_pointers[subprogram_pointer]++;
    subprogram_pointer = m_subprogram_pointer;
    instruction_pointers[m_subprogram_pointer] = 0;
}
