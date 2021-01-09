#include <limits>
#include "divide.h"
#include "utils.h"

const std::string Divide::MNEMONIC = "DIV";

Divide::Divide(uint16_t input1_pointer, uint16_t input2_pointer, uint16_t output_pointer) :
    m_input1_pointer(input1_pointer),
    m_input2_pointer(input2_pointer),
    m_output_pointer(output_pointer)
{
}

void Divide::operator()(std::vector<float>& memory, uint8_t& subprogram_pointer,
    std::vector<uint16_t>& instruction_pointers, std::vector<uint8_t>& return_pointers) const
{
    (void)return_pointers;

    if (memory[m_input2_pointer] == 0) {
        if (memory[m_input1_pointer] == 0) {
            memory[m_output_pointer] = 1;
        } else {
            if (memory[m_input1_pointer] > 0) {
                memory[m_output_pointer] = std::numeric_limits<float>::max();
            } else {
                memory[m_output_pointer] = -std::numeric_limits<float>::max();
            }
        }
    } else {
        memory[m_output_pointer] = memory[m_input1_pointer] / memory[m_input2_pointer];
        memory[m_output_pointer] = Utils::clamp(memory[m_output_pointer]);
    }

    instruction_pointers[subprogram_pointer]++;
}

std::vector<std::string> Divide::toStringTokens() const
{
    return std::vector<std::string>{ MNEMONIC, std::to_string(m_input1_pointer), std::to_string(m_input2_pointer), std::to_string(m_output_pointer) };
}

std::unique_ptr<Instruction> Divide::fromStringTokens(const std::vector<std::string>& tokens)
{
    if (tokens.size() != 4) {
        return nullptr;
    }

    if (tokens[0] != MNEMONIC) {
        return nullptr;
    }

    uint16_t input1_pointer;
    if (!Utils::stringToUnsignedShort(tokens[1], input1_pointer)) {
        return nullptr;
    }

    uint16_t input2_pointer;
    if (!Utils::stringToUnsignedShort(tokens[2], input2_pointer)) {
        return nullptr;
    }

    uint16_t output_pointer;
    if (!Utils::stringToUnsignedShort(tokens[3], output_pointer)) {
        return nullptr;
    }

    return std::make_unique<Divide>(input1_pointer, input2_pointer, output_pointer);
}
