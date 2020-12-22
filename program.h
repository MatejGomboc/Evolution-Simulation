#ifndef PROGRAM_H
#define PROGRAM_H

#include "instruction.h"

class Program
{
public:
    void execute();
private:
    std::vector<std::vector<std::unique_ptr<Instruction>>> m_subprograms;
    std::vector<float> m_memory;
    unsigned short m_subprogram_pointer;
    std::vector<unsigned short> m_instruction_pointers;
    unsigned short m_return_pointer;
};

#endif // PROGRAM_H
