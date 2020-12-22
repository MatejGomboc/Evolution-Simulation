#ifndef ADD_H
#define ADD_H

#include "instruction.h"

class Add : public Instruction
{
public:
    Add(unsigned input1_pointer, unsigned input2_pointer, unsigned output_pointer);
    void operator()(std::vector<float>& memory, unsigned& subprogram_pointer, std::vector<unsigned>& instruction_pointers) const override;
private:
    unsigned m_input1_pointer;
    unsigned m_input2_pointer;
    unsigned m_output_pointer;
};

#endif // ADD_H
