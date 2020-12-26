#ifndef RETURN_H
#define RETURN_H

#include "instruction.h"

class Return : public Instruction
{
public:
    static const std::string MNEMONIC;
    void operator()(std::vector<float>& memory, unsigned char& subprogram_pointer, std::vector<unsigned short>& instruction_pointers,
        std::vector<unsigned char>& return_pointers) const override;
    std::vector<std::string> toStringTokens() const override;
    static std::unique_ptr<Instruction> fromStringTokens(const std::vector<std::string>& tokens);
};

#endif // RETURN_H
