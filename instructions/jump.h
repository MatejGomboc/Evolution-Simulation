#ifndef JUMP_H
#define JUMP_H

#include "instruction.h"

class Jump : public Instruction
{
public:
    Jump(unsigned subprogram_pointer);
    void operator()(std::vector<float>& memory, unsigned& subprogram_pointer, std::vector<unsigned>& instruction_pointers) const override;
private:
    unsigned m_subprogram_pointer;
};

#endif // JUMP_H
