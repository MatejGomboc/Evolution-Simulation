#include "loop.h"
#include "utils.h"

const std::string Loop::MNEMONIC = "LOP";

Loop::Loop(unsigned char subprogram_pointer) :
    m_subprogram_pointer(subprogram_pointer)
{
}

void Loop::operator()(std::vector<float>& memory, unsigned char& subprogram_pointer,
    std::vector<unsigned short>& instruction_pointers, std::vector<unsigned char>& return_pointers) const
{
    (void)memory;
    (void)return_pointers;

    instruction_pointers[subprogram_pointer]++;
    return_pointers.push_back(subprogram_pointer);

    subprogram_pointer = m_subprogram_pointer;
    instruction_pointers[m_subprogram_pointer] = 0;
}

std::vector<std::string> Loop::toStringTokens() const
{
    return std::vector<std::string>{ MNEMONIC, std::to_string(m_subprogram_pointer) };
}

std::unique_ptr<Instruction> Loop::fromStringTokens(const std::vector<std::string>& tokens)
{
    if (tokens.size() != 2) {
        return nullptr;
    }

    if (tokens[0] != MNEMONIC) {
        return nullptr;
    }

    unsigned char subprogram_pointer;
    if (!Utils::stringToUnsignedChar(tokens[1], subprogram_pointer)) {
        return nullptr;
    }

    return std::make_unique<Loop>(subprogram_pointer);
}
