#ifndef NOT_H
#define NOT_H

#include "instruction.h"

class Not : public Instruction
{
public:
    static const std::string MNEMONIC;
    Not(uint16_t input_pointer, uint16_t output_pointer);
    void operator()(std::vector<float>& memory, uint8_t& subprogram_pointer, std::vector<uint16_t>& instruction_pointers,
        std::vector<uint8_t>& return_pointers) const override;
    std::vector<std::string> toStringTokens() const override;
    static std::unique_ptr<Instruction> fromStringTokens(const std::vector<std::string>& tokens);
    std::vector<uint8_t> toByteArray() const override;
    static std::unique_ptr<Instruction> fromByteArray(const std::vector<uint8_t>& array, size_t offset = 0);

private:
    uint16_t m_input_pointer;
    uint16_t m_output_pointer;
};

#endif // NOT_H
