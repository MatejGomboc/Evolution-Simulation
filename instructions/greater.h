#ifndef GREATER_H
#define GREATER_H

#include "instruction.h"

class Greater : public Instruction
{
public:
    Greater(unsigned short input1_pointer, unsigned short input2_pointer, unsigned short output_pointer);
    void operator()(std::vector<float>& memory, unsigned char& subprogram_pointer, std::vector<unsigned short>& instruction_pointers, std::vector<unsigned char>& return_pointers) const override;
private:
    unsigned short m_input1_pointer;
    unsigned short m_input2_pointer;
    unsigned short m_output_pointer;
};

#endif // GREATER_H
