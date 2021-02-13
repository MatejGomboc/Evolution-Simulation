#ifndef DIVIDE_H
#define DIVIDE_H

#include "instruction.h"

class Divide : public Instruction
{
public:
    static const std::string MNEMONIC;
    Divide(uint16_t input1_memory_address, uint16_t input2_memory_address, uint16_t output_memory_address);
    void operator()(std::vector<int32_t>& memory, uint8_t& subprogram_index, std::vector<uint16_t>& instruction_addresses,
        std::vector<uint8_t>& return_indices) const override;
    std::vector<std::string> toStringTokens() const override;
    static std::unique_ptr<Instruction> fromStringTokens(const std::vector<std::string>& tokens);
    std::vector<uint8_t> toByteArray() const override;
    static std::unique_ptr<Instruction> fromByteArray(const std::vector<uint8_t>& array, size_t& offset);

private:
    uint16_t m_input1_memory_address;
    uint16_t m_input2_memory_address;
    uint16_t m_output_address;
};

#endif // DIVIDE_H
