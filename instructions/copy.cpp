#include "copy.h"

Copy::Copy(unsigned short input_pointer, unsigned short output_pointer) :
    m_input_pointer(input_pointer),
    m_output_pointer(output_pointer)
{
}

void Copy::operator()(std::vector<float>& memory, unsigned short& subprogram_pointer, std::vector<unsigned short>& instruction_pointers, unsigned short& return_pointer) const
{
    (void)return_pointer;
    memory[m_output_pointer] = memory[m_input_pointer];
    instruction_pointers[subprogram_pointer]++;
}