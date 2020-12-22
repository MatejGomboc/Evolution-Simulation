#ifndef COPY_H
#define COPY_H

#include "instruction.h"

class Copy : public Instruction
{
public:
    Copy(unsigned input_pointer, unsigned output_pointer);
    void operator()(std::vector<float>& memory, unsigned& subprogram_pointer, std::vector<unsigned>& instruction_pointers) const override;
private:
    unsigned m_input_pointer;
    unsigned m_output_pointer;
};

#endif // COPY_H
