#ifndef NOP_H
#define NOP_H

#include "instruction.h"

class Nop : public Instruction
{
public:
    void operator()(std::vector<float>& memory, unsigned& subprogram_pointer, std::vector<unsigned>& instruction_pointers) const override;
};

#endif // NOP_H
