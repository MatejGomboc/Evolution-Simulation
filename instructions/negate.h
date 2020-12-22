#ifndef NEGATE_H
#define NEGATE_H

#include "instruction.h"

class Negate : public Instruction
{
public:
    Negate(unsigned short input_pointer, unsigned short output_pointer);
    void operator()(std::vector<float>& memory, unsigned short& subprogram_pointer, std::vector<unsigned short>& instruction_pointers, unsigned short& return_pointer) const override;
private:
    unsigned short m_input_pointer;
    unsigned short m_output_pointer;
};

#endif // NEGATE_H
