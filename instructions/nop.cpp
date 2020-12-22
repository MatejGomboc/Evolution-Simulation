#include "nop.h"

void Nop::operator()(std::vector<float>& memory, unsigned short& subprogram_pointer, std::vector<unsigned short>& instruction_pointers, unsigned short& return_pointer) const
{
    (void)memory;
    (void)return_pointer;
    instruction_pointers[subprogram_pointer]++;
}
