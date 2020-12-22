#include "nop.h"

void Nop::operator()(std::vector<float>& memory, unsigned& subprogram_pointer, std::vector<unsigned>& instruction_pointers, unsigned& return_pointer) const
{
    (void)memory;
    (void)return_pointer;
    instruction_pointers[subprogram_pointer]++;
}
