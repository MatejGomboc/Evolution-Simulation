#ifndef INIT_H
#define INIT_H

#include "instruction.h"

class Init : public Instruction
{
public:
    Init(float value, unsigned pointer);
    void operator()(std::vector<float>& memory, unsigned& subprogram_pointer, std::vector<unsigned>& instruction_pointers) const override;
private:
    float m_value;
    unsigned m_pointer;
};

#endif // INIT_H
