#ifndef INCREASE_H
#define INCREASE_H

#include "instruction.h"

class Increase : public Instruction
{
public:
    Increase(unsigned input_pointer, unsigned output_pointer);
    void operator()(std::vector<float>& memory, unsigned& subprogram_pointer, std::vector<unsigned>& instruction_pointers) const override;
private:
    unsigned m_input_pointer;
    unsigned m_output_pointer;
};

#endif // INCREASE_H
