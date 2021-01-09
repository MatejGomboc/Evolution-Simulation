#include "init.h"
#include "utils.h"

const std::string Init::MNEMONIC = "INI";

Init::Init(float value, uint16_t pointer) :
    m_value(value),
    m_pointer(pointer)
{
}

void Init::operator()(std::vector<float>& memory, uint8_t& subprogram_pointer,
    std::vector<uint16_t>& instruction_pointers, std::vector<uint8_t>& return_pointers) const
{
    (void)return_pointers;
    memory[m_pointer] = m_value;
    instruction_pointers[subprogram_pointer]++;
}

std::vector<std::string> Init::toStringTokens() const
{
    return std::vector<std::string>{ MNEMONIC, std::to_string(m_value), std::to_string(m_pointer) };
}

std::unique_ptr<Instruction> Init::fromStringTokens(const std::vector<std::string>& tokens)
{
    if (tokens.size() != 3) {
        return nullptr;
    }

    if (tokens[0] != MNEMONIC) {
        return nullptr;
    }

    float value;
    if (Utils::stringToFloat(tokens[1], value)) {
        return nullptr;
    }

    uint16_t pointer;
    if (!Utils::stringToUnsignedShort(tokens[2], pointer)) {
        return nullptr;
    }

    return std::make_unique<Init>(value, pointer);
}
