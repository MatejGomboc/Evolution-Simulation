#include "nop.h"

const std::string Nop::MNEMONIC = "NOP";

void Nop::operator()(std::vector<float>& memory, unsigned char& subprogram_pointer,
    std::vector<unsigned short>& instruction_pointers, std::vector<unsigned char>& return_pointers) const
{
    (void)memory;
    (void)return_pointers;
    instruction_pointers[subprogram_pointer]++;
}

std::vector<std::string> Nop::toStringTokens() const
{
    return std::vector<std::string>{MNEMONIC};
}

std::unique_ptr<Instruction> Nop::fromStringTokens(const std::vector<std::string>& tokens)
{
    if (tokens[0] != MNEMONIC) {
        return nullptr;
    }

    return nullptr;
}
