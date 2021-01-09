#include "nop.h"
#include "utils.h"

const std::string Nop::MNEMONIC = "NOP";

void Nop::operator()(std::vector<float>& memory, uint8_t& subprogram_pointer,
    std::vector<uint16_t>& instruction_pointers, std::vector<uint8_t>& return_pointers) const
{
    (void)memory;
    (void)return_pointers;
    instruction_pointers[subprogram_pointer]++;
}

std::vector<std::string> Nop::toStringTokens() const
{
    return std::vector<std::string>{ MNEMONIC };
}

std::unique_ptr<Instruction> Nop::fromStringTokens(const std::vector<std::string>& tokens)
{
    if (tokens.size() != 1) {
        return nullptr;
    }

    if (tokens[0] != MNEMONIC) {
        return nullptr;
    }

    return std::make_unique<Nop>();
}

std::vector<uint8_t> Nop::toByteArray() const
{
}
