#ifndef NOP_H
#define NOP_H

#include "instruction.h"

class Nop : public Instruction
{
public:
    static const std::string MNEMONIC;
    void operator()(std::vector<float>& memory, uint8_t& subprogram_pointer, std::vector<uint16_t>& instruction_pointers,
        std::vector<uint8_t>& return_pointers) const override;
    std::vector<std::string> toStringTokens() const override;
    static std::unique_ptr<Instruction> fromStringTokens(const std::vector<std::string>& tokens);
};

#endif // NOP_H
