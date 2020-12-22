#ifndef NOT_H
#define NOT_H

#include "instruction.h"

class Not : public Instruction
{
public:
    Not(unsigned input_pointer, unsigned output_pointer);
    void operator()(std::vector<float>& memory, unsigned& subprogram_pointer, std::vector<unsigned>& instruction_pointers) const override;
private:
    unsigned m_input_pointer;
    unsigned m_output_pointer;
};

#endif // NOT_H
