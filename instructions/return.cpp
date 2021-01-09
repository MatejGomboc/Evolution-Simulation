#include "return.h"
#include "utils.h"

const std::string Return::MNEMONIC = "RET";

void Return::operator()(std::vector<float>& memory, uint8_t& subprogram_pointer,
    std::vector<uint16_t>& instruction_pointers, std::vector<uint8_t>& return_pointers) const
{
    (void)memory;
    (void)instruction_pointers;
    subprogram_pointer = return_pointers.back();
    return_pointers.pop_back();
}

std::vector<std::string> Return::toStringTokens() const
{
    return std::vector<std::string>{ MNEMONIC };
}

std::unique_ptr<Instruction> Return::fromStringTokens(const std::vector<std::string>& tokens)
{
    if (tokens.size() != 1) {
        return nullptr;
    }

    if (tokens[0] != MNEMONIC) {
        return nullptr;
    }

    return std::make_unique<Return>();
}
