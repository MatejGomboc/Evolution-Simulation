#include "return.h"

void Return::operator()(std::vector<float>& memory, unsigned short& subprogram_pointer, std::vector<unsigned short>& instruction_pointers, std::vector<unsigned short>& return_pointers) const
{
    (void)memory;
    (void)instruction_pointers;
    subprogram_pointer = return_pointers.back();
    return_pointers.pop_back();
}
