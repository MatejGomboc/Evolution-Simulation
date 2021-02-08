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
    uint8_t m_subprogram_index = 0;
    std::vector<uint16_t> m_instruction_addresses;
    std::vector<uint8_t> m_return_addresses;

    uint16_t generateRandomMemoryAddress(bool adding_allowed = false, uint16_t max_allowed_memory = 0);
    void addNop(uint8_t subprogram_index);
    void addRandomInit(uint8_t subprogram_index, bool adding_memory_allowed = false, uint16_t max_allowed_memory = 0);
    void addRandomCopy(uint8_t subprogram_index, bool adding_memory_allowed = false, uint16_t max_allowed_memory = 0);
    void addRandomMathLogicInstruction(uint8_t subprogram_index, bool adding_memory_allowed = false, uint16_t max_allowed_memory = 0);
};

#endif // PROGRAM_H
