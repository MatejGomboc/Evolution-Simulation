#ifndef LOOP_H
#define LOOP_H

#include "instruction.h"

class Loop : public Instruction
{
public:
    static const std::string MNEMONIC;
    Loop(uint8_t subprogram_pointer);
    void operator()(std::vector<float>& memory, uint8_t& subprogram_pointer, std::vector<uint16_t>& instruction_pointers,
        std::vector<uint8_t>& return_pointers) const override;
    std::vector<std::string> toStringTokens() const override;
    static std::unique_ptr<Instruction> fromStringTokens(const std::vector<std::string>& tokens);
    std::vector<uint8_t> toByteArray() const override;

private:
    uint8_t m_subprogram_pointer;
};

#endif // LOOP_H
