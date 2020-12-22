#ifndef OR_H
#define OR_H

#include "instruction.h"

class Or : public Instruction
{
public:
    Or(unsigned input1_pointer, unsigned input2_pointer, unsigned output_pointer);
    void operator()(std::vector<float>& memory, unsigned& subprogram_pointer, std::vector<unsigned>& instruction_pointers) const override;
private:
    unsigned m_input1_pointer;
    unsigned m_input2_pointer;
    unsigned m_output_pointer;
};

#endif // OR_H
