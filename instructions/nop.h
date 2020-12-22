#ifndef NOP_H
#define NOP_H

#include "instruction.h"

class Nop : public Instruction
{
public:
    void operator()(std::vector<float>& memory, unsigned short& subprogram_pointer, std::vector<unsigned short>& instruction_pointers, std::vector<unsigned short>& return_pointers) const override;
};

#endif // NOP_H
