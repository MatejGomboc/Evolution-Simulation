#ifndef CONDITION_H
#define CONDITION_H

#include "instruction.h"

class Condition : public Instruction
{
public:
    Condition(unsigned short input_pointer, unsigned char subprogram_pointer);
    void operator()(std::vector<float>& memory, unsigned char& subprogram_pointer, std::vector<unsigned short>& instruction_pointers, std::vector<unsigned char>& return_pointers) const override;
private:
    unsigned short m_input_pointer;
    unsigned char m_subprogram_pointer;
};

#endif // CONDITION_H
