#ifndef EQUAL_H
#define EQUAL_H

#include "instruction.h"

class Equal : public Instruction
{
public:
    static const std::string MNEMONIC;
    Equal(uint16_t input1_pointer, uint16_t input2_pointer, uint16_t output_pointer);
    void operator()(std::vector<float>& memory, uint8_t& subprogram_pointer, std::vector<uint16_t>& instruction_pointers,
        std::vector<uint8_t>& return_pointers) const override;
    std::vector<std::string> toStringTokens() const override;
    static std::unique_ptr<Instruction> fromStringTokens(const std::vector<std::string>& tokens);

private:
    uint16_t m_input1_pointer;
    uint16_t m_input2_pointer;
    uint16_t m_output_pointer;
};

#endif // EQUAL_H
