#ifndef NEGATE_H
#define NEGATE_H

#include "instruction.h"

class Negate : public Instruction
{
public:
    Negate(unsigned pointer);
    void operator()(std::vector<float>& memory, unsigned& subprogram_pointer, std::vector<unsigned>& instruction_pointers) const override;
private:
    unsigned m_pointer;
};

#endif // NEGATE_H
