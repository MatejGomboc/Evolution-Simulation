#ifndef INIT_H
#define INIT_H

#include "instruction.h"

class Init : public Instruction
{
public:
    static const std::string MNEMONIC;
    Init(int32_t value, uint16_t address);
    void operator()(std::vector<int32_t>& memory, uint8_t& subprogram_index, std::vector<uint16_t>& instruction_addresses,
        std::vector<uint8_t>& return_indices) const override;
    std::vector<std::string> toStringTokens() const override;
    static std::unique_ptr<Instruction> fromStringTokens(const std::vector<std::string>& tokens);
    std::vector<uint8_t> toByteArray() const override;
    static std::unique_ptr<Instruction> fromByteArray(const std::vector<uint8_t>& array, size_t& offset);

private:
    int32_t m_value;
    uint16_t m_address;
};

#endif // INIT_H
