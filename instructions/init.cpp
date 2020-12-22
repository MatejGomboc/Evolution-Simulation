#include "init.h"

Init::Init(float value, unsigned short pointer) :
    m_value(value),
    m_pointer(pointer)
{
}

void Init::operator()(std::vector<float>& memory, unsigned short& subprogram_pointer, std::vector<unsigned short>& instruction_pointers, std::vector<unsigned short>& return_pointers) const
{
    (void)return_pointers;
    memory[m_pointer] = m_value;
    instruction_pointers[subprogram_pointer]++;
}
