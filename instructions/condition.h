#ifndef CONDITION_H
#define CONDITION_H

#include "instruction.h"

class Condition : public Instruction
{
public:
    Condition(unsigned short input_pointer, unsigned short subprogram_pointer);
    void operator()(std::vector<float>& memory, unsigned short& subprogram_pointer, std::vector<unsigned short>& instruction_pointers, unsigned short& return_pointer) const override;
private:
    unsigned short m_input_pointer;
    unsigned short m_subprogram_pointer;
};

#endif // CONDITION_H
