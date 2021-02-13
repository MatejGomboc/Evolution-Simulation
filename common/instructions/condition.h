#ifndef CONDITION_H
#define CONDITION_H

#include "instruction.h"

class Condition : public Instruction
{
public:
    static const std::string MNEMONIC;
    Condition(uint16_t input_memory_address, uint8_t subprogram_index);
    void operator()(std::vector<int32_t>& memory, uint8_t& subprogram_index, std::vector<uint16_t>& instruction_addresses,
        std::vector<uint8_t>& return_indices) const override;
    std::vector<std::string> toStringTokens() const override;
    static std::unique_ptr<Instruction> fromStringTokens(const std::vector<std::string>& tokens);
    std::vector<uint8_t> toByteArray() const override;
    static std::unique_ptr<Instruction> fromByteArray(const std::vector<uint8_t>& array, size_t& offset);

private:
    uint16_t m_input_address;
    uint8_t m_subprogram_index;
};

#endif // CONDITION_H
