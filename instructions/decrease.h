#ifndef DECREASE_H
#define DECREASE_H

#include "instruction.h"

class Decrease : public Instruction
{
public:
    static const std::string MNEMONIC;
    Decrease(uint16_t input_pointer, uint16_t output_pointer);
    void operator()(std::vector<float>& memory, uint8_t& subprogram_pointer, std::vector<uint16_t>& instruction_pointers,
        std::vector<uint8_t>& return_pointers) const override;
    std::vector<std::string> toStringTokens() const override;
    static std::unique_ptr<Instruction> fromStringTokens(const std::vector<std::string>& tokens);
    std::vector<uint8_t> toByteArray() const override;

private:
    uint16_t m_input_pointer;
    uint16_t m_output_pointer;
};

#endif // DECREASE_H
