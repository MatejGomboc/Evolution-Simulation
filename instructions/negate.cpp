#include "negate.h"
#include "utils.h"

const std::string Negate::MNEMONIC = "NEG";

Negate::Negate(uint16_t input_pointer, uint16_t output_pointer) :
    m_input_pointer(input_pointer),
    m_output_pointer(output_pointer)
{
}

void Negate::operator()(std::vector<float>& memory, uint8_t& subprogram_pointer,
    std::vector<uint16_t>& instruction_pointers, std::vector<uint8_t>& return_pointers) const
{
    (void)return_pointers;
    memory[m_output_pointer] = (-1) * memory[m_input_pointer];
    instruction_pointers[subprogram_pointer]++;
}

std::vector<std::string> Negate::toStringTokens() const
{
    return std::vector<std::string>{ MNEMONIC, std::to_string(m_input_pointer), std::to_string(m_output_pointer) };
}

std::unique_ptr<Instruction> Negate::fromStringTokens(const std::vector<std::string>& tokens)
{
    if (tokens.size() != 3) {
        return nullptr;
    }

    if (tokens[0] != MNEMONIC) {
        return nullptr;
    }

    uint16_t input_pointer;
    if (!Utils::stringToUnsignedShort(tokens[1], input_pointer)) {
        return nullptr;
    }

    uint16_t output_pointer;
    if (!Utils::stringToUnsignedShort(tokens[2], output_pointer)) {
        return nullptr;
    }

    return std::make_unique<Negate>(input_pointer, output_pointer);
}

std::vector<uint8_t> Negate::toByteArray() const
{
}
