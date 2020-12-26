#include "init.h"

const std::string Init::MNEMONIC = "INI";

Init::Init(float value, unsigned short pointer) :
    m_value(value),
    m_pointer(pointer)
{
}

void Init::operator()(std::vector<float>& memory, unsigned char& subprogram_pointer,
    std::vector<unsigned short>& instruction_pointers, std::vector<unsigned char>& return_pointers) const
{
    (void)return_pointers;
    memory[m_pointer] = m_value;
    instruction_pointers[subprogram_pointer]++;
}

std::vector<std::string> Init::toStringTokens() const
{
    return std::vector<std::string>{MNEMONIC, std::to_string(m_value), std::to_string(m_pointer)};
}
