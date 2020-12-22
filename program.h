#ifndef PROGRAM_H
#define PROGRAM_H

#include <limits>
#include "instruction.h"

class Program
{
public:
    static constexpr unsigned short MAX_INSTRUCTIONS = std::numeric_limits<unsigned short>::max();
    static constexpr unsigned short MAX_DATA = std::numeric_limits<unsigned short>::max();
    static constexpr unsigned char MAX_SUBPROGRAMS = std::numeric_limits<unsigned char>::max();
    void execute();
private:
    std::vector<std::vector<std::unique_ptr<Instruction>>> m_subprograms;
    std::vector<float> m_memory;
    unsigned char m_subprogram_pointer;
    std::vector<unsigned short> m_instruction_pointers;
    std::vector<unsigned char> m_return_pointers;
};

#endif // PROGRAM_H
