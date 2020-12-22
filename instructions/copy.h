#ifndef COPY_H
#define COPY_H

#include "instruction.h"

class Copy : public Instruction
{
public:
    Copy(unsigned short input_pointer, unsigned short output_pointer);
    void operator()(std::vector<float>& memory, unsigned short& subprogram_pointer, std::vector<unsigned short>& instruction_pointers, unsigned short& return_pointer) const override;
private:
    unsigned short m_input_pointer;
    unsigned short m_output_pointer;
};

#endif // COPY_H
