#ifndef NEGATE_H
#define NEGATE_H

#include "instruction.h"

class Negate : public Instruction
{
public:
    Negate(unsigned short input_pointer, unsigned short output_pointer);
    void operator()(std::vector<float>& memory, unsigned char& subprogram_pointer, std::vector<unsigned short>& instruction_pointers,
        std::vector<unsigned char>& return_pointers) const override;

private:
    unsigned short m_input_pointer;
    unsigned short m_output_pointer;
};

#endif // NEGATE_H
