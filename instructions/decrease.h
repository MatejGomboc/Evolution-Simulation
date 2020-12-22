#ifndef DECREASE_H
#define DECREASE_H

#include "instruction.h"

class Decrease : public Instruction
{
public:
    Decrease(unsigned short input_pointer, unsigned short output_pointer);
    void operator()(std::vector<float>& memory, unsigned short& subprogram_pointer, std::vector<unsigned short>& instruction_pointers, std::vector<unsigned short>& return_pointers) const override;
private:
    unsigned short m_input_pointer;
    unsigned short m_output_pointer;
};

#endif // DECREASE_H
