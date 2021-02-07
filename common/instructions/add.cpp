#include "add.h"
#include "utils.h"

const std::string Add::MNEMONIC = "ADD";

Add::Add(uint16_t input1_pointer, uint16_t input2_pointer, uint16_t output_pointer) :
    m_input1_pointer(input1_pointer),
    m_input2_pointer(input2_pointer),
    m_output_pointer(output_pointer)
{
}

void Add::operator()(std::vector<float>& memory, uint8_t& subprogram_pointer,
    std::vector<uint16_t>& instruction_pointers, std::vector<uint8_t>& return_pointers) const
{
    (void)return_pointers;
    memory[m_output_pointer] = memory[m_input1_pointer] + memory[m_input2_pointer];
    memory[m_output_pointer] = Utils::clamp(memory[m_output_pointer]);
    instruction_pointers[subprogram_pointer]++;
}

std::vector<std::string> Add::toStringTokens() const
{
    return std::vector<std::string>{ MNEMONIC, std::to_string(m_input1_pointer), std::to_string(m_input2_pointer), std::to_string(m_output_pointer) };
}

std::unique_ptr<Instruction> Add::fromStringTokens(const std::vector<std::string>& tokens)
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

    return std::make_unique<Add>(input1_pointer, input2_pointer, output_pointer);
}

std::vector<uint8_t> Add::toByteArray() const
{
    std::vector<uint8_t> array;
    array.push_back(static_cast<uint8_t>(Id::ADD));
    Utils::insertByteArray(array, m_input1_pointer);
    Utils::insertByteArray(array, m_input2_pointer);
    Utils::insertByteArray(array, m_output_pointer);
    return array;
}

std::unique_ptr<Instruction> Add::fromByteArray(const std::vector<uint8_t>& array, size_t& offset)
{
    if (array.size() - offset < sizeof(uint8_t) + sizeof(uint16_t) * 3) {
        return nullptr;
    }

    if (array[offset++] != static_cast<uint8_t>(Id::ADD)) {
        return nullptr;
    }

    uint16_t input1_pointer = Utils::parseByteArray<uint16_t>(array, offset);
    uint16_t input2_pointer = Utils::parseByteArray<uint16_t>(array, offset);
    uint16_t output_pointer = Utils::parseByteArray<uint16_t>(array, offset);

    return std::make_unique<Add>(input1_pointer, input2_pointer, output_pointer);
}
