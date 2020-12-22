#ifndef SUBTRACT_H
#define SUBTRACT_H

#include "instruction.h"

class Subtract : public Instruction
{
public:
    Subtract(unsigned input1_pointer, unsigned input2_pointer, unsigned output_pointer);
    void operator()(std::vector<float>& memory, unsigned& subprogram_pointer, std::vector<unsigned>& instruction_pointers) const override;
private:
    unsigned m_input1_pointer;
    unsigned m_input2_pointer;
    unsigned m_output_pointer;
};

#endif // SUBTRACT_H
