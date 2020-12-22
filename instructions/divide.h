#ifndef DIVIDE_H
#define DIVIDE_H

#include "instruction.h"

class Divide : public Instruction
{
public:
    Divide(unsigned input1_pointer, unsigned input2_pointer, unsigned output_pointer);
    void operator()(std::vector<float>& memory, unsigned& subprogram_pointer, std::vector<unsigned>& instruction_pointers, unsigned& return_pointer) const override;
private:
    unsigned m_input1_pointer;
    unsigned m_input2_pointer;
    unsigned m_output_pointer;
};

#endif // DIVIDE_H
