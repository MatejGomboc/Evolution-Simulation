#include "nop.h"

void Nop::operator()(std::vector<float>& memory, unsigned short& subprogram_pointer, std::vector<unsigned short>& instruction_pointers, std::vector<unsigned short>& return_pointers) const
{
    (void)memory;
    (void)return_pointers;
    instruction_pointers[subprogram_pointer]++;
}
