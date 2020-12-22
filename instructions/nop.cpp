#include "nop.h"

void Nop::operator()(std::vector<float>& memory, unsigned char& subprogram_pointer, std::vector<unsigned short>& instruction_pointers, std::vector<unsigned char>& return_pointers) const
{
    (void)memory;
    (void)return_pointers;
    instruction_pointers[subprogram_pointer]++;
}
