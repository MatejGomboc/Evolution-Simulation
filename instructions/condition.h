#ifndef CONDITION_H
#define CONDITION_H

#include "instruction.h"

class Condition : public Instruction
{
public:
    static const std::string MNEMONIC;
    Condition(unsigned short input_pointer, unsigned char subprogram_pointer);
    void operator()(std::vector<float>& memory, unsigned char& subprogram_pointer, std::vector<unsigned short>& instruction_pointers,
        std::vector<unsigned char>& return_pointers) const override;
    std::vector<std::string> toStringTokens() const override;
    static std::unique_ptr<Instruction> fromStringTokens(const std::vector<std::string>& tokens);

private:
    unsigned short m_input_pointer;
    unsigned char m_subprogram_pointer;
};

#endif // CONDITION_H
