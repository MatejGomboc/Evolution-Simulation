#include "loop.h"

Loop::Loop(unsigned char subprogram_pointer) :
    m_subprogram_pointer(subprogram_pointer)
{
}

void Loop::operator()(std::vector<float>& memory, unsigned char& subprogram_pointer,
    std::vector<unsigned short>& instruction_pointers, std::vector<unsigned char>& return_pointers) const
{
    (void)memory;
    (void)return_pointers;

    instruction_pointers[subprogram_pointer]++;
    return_pointers.push_back(subprogram_pointer);

    subprogram_pointer = m_subprogram_pointer;
    instruction_pointers[m_subprogram_pointer] = 0;
}
