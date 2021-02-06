#ifndef INCREASE_H
#define INCREASE_H

#include "instruction.h"

class Increase : public Instruction
{
public:
    static const std::string MNEMONIC;
    Increase(uint16_t input_pointer, uint16_t output_pointer);
    void operator()(std::vector<float>& memory, uint8_t& subprogram_pointer, std::vector<uint16_t>& instruction_pointers,
        std::vector<uint8_t>& return_pointers) const override;
    std::vector<std::string> toStringTokens() const override;
    static std::unique_ptr<Instruction> fromStringTokens(const std::vector<std::string>& tokens);
    std::vector<uint8_t> toByteArray() const override;
    static std::unique_ptr<Instruction> fromByteArray(const std::vector<uint8_t>& array, size_t& offset);

private:
    uint16_t m_input_pointer;
    uint16_t m_output_pointer;
};

#endif // INCREASE_H
