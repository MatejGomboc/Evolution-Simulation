#include "return.h"

void Return::operator()(std::vector<float>& memory, unsigned& subprogram_pointer, std::vector<unsigned>& instruction_pointers, unsigned& return_pointer) const
{
    (void)memory;
    (void)instruction_pointers;
    subprogram_pointer = return_pointer;
}
