#ifndef INIT_H
#define INIT_H

#include "instruction.h"

class Init : public Instruction
{
public:
    Init(float value, unsigned short pointer);
    void operator()(std::vector<float>& memory, unsigned short& subprogram_pointer, std::vector<unsigned short>& instruction_pointers, unsigned short& return_pointer) const override;
private:
    float m_value;
    unsigned short m_pointer;
};

#endif // INIT_H
