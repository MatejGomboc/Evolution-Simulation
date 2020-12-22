#include "init.h"

Init::Init(float value, unsigned pointer) :
    m_value(value),
    m_pointer(pointer)
{
}

void Init::operator()(std::vector<float>& memory, unsigned& subprogram_pointer, std::vector<unsigned>& instruction_pointers, unsigned& return_pointer) const
{
    (void)return_pointer;
    memory[m_pointer] = m_value;
    instruction_pointers[subprogram_pointer]++;
}
