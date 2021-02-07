#ifndef PROGRAM_H
#define PROGRAM_H

#include <limits>
#include "instruction.h"

class Program
{
public:
    static constexpr uint16_t MAX_INSTRUCTIONS = std::numeric_limits<uint16_t>::max();
    static constexpr uint16_t MAX_DATA = std::numeric_limits<uint16_t>::max();
    static constexpr uint8_t MAX_SUBPROGRAMS = std::numeric_limits<uint8_t>::max();

    static Program random();

    Program();
    void execute();

private:
    std::vector<std::vector<std::unique_ptr<Instruction>>> m_subprograms;
    std::vector<float> m_memory;
    uint8_t m_subprogram_pointer = 0;
    std::vector<uint16_t> m_instruction_pointers;
    std::vector<uint8_t> m_return_pointers;

    static std::unique_ptr<Instruction> randomArithmeticalLogicalInstruction(uint16_t input_pointer, uint16_t output_pointer);
    static std::unique_ptr<Instruction> randomArithmeticalLogicalInstruction(uint16_t input1_pointer, uint16_t input2_pointer, uint16_t output_pointer);
};

#endif // PROGRAM_H