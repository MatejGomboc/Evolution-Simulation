#ifndef RETURN_H
#define RETURN_H

#include "instruction.h"

class Return : public Instruction
{
public:
    void operator()(std::vector<float>& memory, unsigned char& subprogram_pointer, std::vector<unsigned short>& instruction_pointers, std::vector<unsigned char>& return_pointers) const override;
};

#endif // RETURN_H
