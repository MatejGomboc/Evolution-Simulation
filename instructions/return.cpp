#include "return.h"

void Return::operator()(std::vector<float>& memory, unsigned short& subprogram_pointer, std::vector<unsigned short>& instruction_pointers, unsigned short& return_pointer) const
{
    (void)memory;
    (void)instruction_pointers;
    subprogram_pointer = return_pointer;
}
