#include "increase.h"
#include "utils.h"

const std::string Increase::MNEMONIC = "INC";

Increase::Increase(uint16_t input_pointer, uint16_t output_pointer) :
    m_input_pointer(input_pointer),
    m_output_pointer(output_pointer)
{
}

void Increase::operator()(std::vector<float>& memory, uint8_t& subprogram_pointer,
    std::vector<uint16_t>& instruction_pointers, std::vector<uint8_t>& return_pointers) const
{
    (void)return_pointers;
    memory[m_output_pointer] = memory[m_input_pointer] + 1;
    memory[m_output_pointer] = Utils::clamp(memory[m_output_pointer]);
    instruction_pointers[subprogram_pointer]++;
}

std::vector<std::string> Increase::toStringTokens() const
{
    return std::vector<std::string>{ MNEMONIC, std::to_string(m_input_pointer), std::to_string(m_output_pointer) };
}

std::unique_ptr<Instruction> Increase::fromStringTokens(const std::vector<std::string>& tokens)
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

    return std::make_unique<Increase>(input_pointer, output_pointer);
}

std::vector<uint8_t> Increase::toByteArray() const
{
    std::vector<uint8_t> array;
    array.push_back(static_cast<uint8_t>(Id::INCREASE));
    Utils::insertByteArray(array, m_input_pointer);
    Utils::insertByteArray(array, m_output_pointer);
    return array;
}

std::unique_ptr<Instruction> Increase::fromByteArray(const std::vector<uint8_t>& array, size_t& offset)
{
    if (array.size() - offset < sizeof(uint8_t) + sizeof(uint16_t) * 2) {
        return nullptr;
    }

    if (array[offset++] != static_cast<uint8_t>(Id::INCREASE)) {
        return nullptr;
    }

    uint16_t input_pointer = Utils::parseByteArray<uint16_t>(array, offset);
    uint16_t output_pointer = Utils::parseByteArray<uint16_t>(array, offset);

    return std::make_unique<Increase>(input_pointer, output_pointer);
}
