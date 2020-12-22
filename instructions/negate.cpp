#include "negate.h"

Negate::Negate(unsigned pointer) :
    m_pointer(pointer)
{
}

void Negate::operator()(std::vector<float>& memory, unsigned& subprogram_pointer, std::vector<unsigned>& instruction_pointers) const
{
    memory[m_pointer] *= -1;
    instruction_pointers[subprogram_pointer]++;
}
