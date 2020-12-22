#ifndef SMALLER_H
#define SMALLER_H

#include "instruction.h"

class Smaller : public Instruction
{
public:
    Smaller(unsigned short input1_pointer, unsigned short input2_pointer, unsigned short output_pointer);
    void operator()(std::vector<float>& memory, unsigned short& subprogram_pointer, std::vector<unsigned short>& instruction_pointers, unsigned short& return_pointer) const override;
private:
    unsigned short m_input1_pointer;
    unsigned short m_input2_pointer;
    unsigned short m_output_pointer;
};

#endif // SMALLER_H
