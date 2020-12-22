#ifndef NOT_H
#define NOT_H

#include "instruction.h"

class Not : public Instruction
{
public:
    Not(unsigned short input_pointer, unsigned short output_pointer);
    void operator()(std::vector<float>& memory, unsigned char& subprogram_pointer, std::vector<unsigned short>& instruction_pointers, std::vector<unsigned char>& return_pointers) const override;
private:
    unsigned short m_input_pointer;
    unsigned short m_output_pointer;
};

#endif // NOT_H
