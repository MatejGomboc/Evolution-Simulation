#include "subtract.h"
#include "utils.h"

const std::string Subtract::MNEMONIC = "SUB";

Subtract::Subtract(unsigned short input1_pointer, unsigned short input2_pointer, unsigned short output_pointer) :
    m_input1_pointer(input1_pointer),
    m_input2_pointer(input2_pointer),
    m_output_pointer(output_pointer)
{
}

void Subtract::operator()(std::vector<float>& memory, unsigned char& subprogram_pointer,
    std::vector<unsigned short>& instruction_pointers, std::vector<unsigned char>& return_pointers) const
{
    (void)return_pointers;
    memory[m_output_pointer] = memory[m_input1_pointer] - memory[m_input2_pointer];
    memory[m_output_pointer] = Utils::clamp(memory[m_output_pointer]);
    instruction_pointers[subprogram_pointer]++;
}

std::vector<std::string> Subtract::toStringTokens() const
{
    return std::vector<std::string>{ MNEMONIC, std::to_string(m_input1_pointer), std::to_string(m_input2_pointer), std::to_string(m_output_pointer) };
}

std::unique_ptr<Instruction> Subtract::fromStringTokens(const std::vector<std::string>& tokens)
{
    if (tokens.size() != 4) {
        return nullptr;
    }

    if (tokens[0] != MNEMONIC) {
        return nullptr;
    }

    unsigned short input1_pointer;
    if (!Utils::stringToUnsignedShort(tokens[1], input1_pointer)) {
        return nullptr;
    }

    unsigned short input2_pointer;
    if (!Utils::stringToUnsignedShort(tokens[2], input2_pointer)) {
        return nullptr;
    }

    unsigned short output_pointer;
    if (!Utils::stringToUnsignedShort(tokens[3], output_pointer)) {
        return nullptr;
    }

    return std::make_unique<Subtract>(input1_pointer, input2_pointer, output_pointer);
}
