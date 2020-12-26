#include "return.h"

const std::string Return::MNEMONIC = "RET";

void Return::operator()(std::vector<float>& memory, unsigned char& subprogram_pointer,
    std::vector<unsigned short>& instruction_pointers, std::vector<unsigned char>& return_pointers) const
{
    (void)memory;
    (void)instruction_pointers;
    subprogram_pointer = return_pointers.back();
    return_pointers.pop_back();
}

std::vector<std::string> Return::toStringTokens() const
{
    return std::vector<std::string>{MNEMONIC};
}

std::unique_ptr<Instruction> Return::fromStringTokens(const std::vector<std::string>& tokens)
{
    if (tokens[0] != MNEMONIC) {
        return nullptr;
    }

    return nullptr;
}
