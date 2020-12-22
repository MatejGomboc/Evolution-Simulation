#ifndef CONDITION_H
#define CONDITION_H

#include "instruction.h"

class Condition : public Instruction
{
public:
    Condition(unsigned input_pointer, unsigned subprogram_pointer);
    void operator()(std::vector<float>& memory, unsigned& subprogram_pointer, std::vector<unsigned>& instruction_pointers) const override;
private:
    unsigned m_input_pointer;
    unsigned m_subprogram_pointer;
};

#endif // CONDITION_H
