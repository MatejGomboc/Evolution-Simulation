#ifndef RETURN_H
#define RETURN_H

#include "instruction.h"

class Return : public Instruction
{
public:
    void operator()(std::vector<float>& memory, unsigned short& subprogram_pointer, std::vector<unsigned short>& instruction_pointers, unsigned short& return_pointer) const override;
};

#endif // RETURN_H
