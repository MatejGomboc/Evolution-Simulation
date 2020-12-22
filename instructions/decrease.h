#ifndef DECREASE_H
#define DECREASE_H

#include "instruction.h"

class Decrease : public Instruction
{
public:
    Decrease(unsigned input_pointer, unsigned output_pointer);
    void operator()(std::vector<float>& memory, unsigned& subprogram_pointer, std::vector<unsigned>& instruction_pointers, unsigned& return_pointer) const override;
private:
    unsigned m_input_pointer;
    unsigned m_output_pointer;
};

#endif // DECREASE_H
