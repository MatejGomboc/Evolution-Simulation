#ifndef LOOP_H
#define LOOP_H

#include "instruction.h"

class Loop : public Instruction
{
public:
    Loop(unsigned short subprogram_pointer);
    void operator()(std::vector<float>& memory, unsigned short& subprogram_pointer, std::vector<unsigned short>& instruction_pointers, unsigned short& return_pointer) const override;
private:
    unsigned short m_subprogram_pointer;
};

#endif // LOOP_H
