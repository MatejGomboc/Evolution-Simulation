#include "nop.h"

void Nop::operator()(std::vector<float>& memory, unsigned& subprogram_pointer, std::vector<unsigned>& instruction_pointers) const
{
    (void)memory;
    instruction_pointers[subprogram_pointer]++;
}
