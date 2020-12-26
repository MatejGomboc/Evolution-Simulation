#ifndef INIT_H
#define INIT_H

#include "instruction.h"

class Init : public Instruction
{
public:
    static const std::string MNEMONIC;
    Init(float value, unsigned short pointer);
    void operator()(std::vector<float>& memory, unsigned char& subprogram_pointer, std::vector<unsigned short>& instruction_pointers,
        std::vector<unsigned char>& return_pointers) const override;
    std::vector<std::string> toStringTokens() const override;

private:
    float m_value;
    unsigned short m_pointer;
};

#endif // INIT_H
