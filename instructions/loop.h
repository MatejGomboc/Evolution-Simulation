#ifndef LOOP_H
#define LOOP_H

#include "instruction.h"

class Loop : public Instruction
{
public:
    static const std::string MNEMONIC;
    Loop(unsigned char subprogram_pointer);
    void operator()(std::vector<float>& memory, unsigned char& subprogram_pointer, std::vector<unsigned short>& instruction_pointers,
        std::vector<unsigned char>& return_pointers) const override;
    std::vector<std::string> toStringTokens() const override;

private:
    unsigned char m_subprogram_pointer;
};

#endif // LOOP_H
