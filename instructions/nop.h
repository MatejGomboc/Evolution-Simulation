#ifndef NOP_H
#define NOP_H

#include "instruction.h"

class Nop : public Instruction
{
public:
    static const std::string MNEMONIC;
    void operator()(std::vector<float>& memory, unsigned char& subprogram_pointer, std::vector<unsigned short>& instruction_pointers,
        std::vector<unsigned char>& return_pointers) const override;
    std::vector<std::string> toStringTokens() const override;
};

#endif // NOP_H
