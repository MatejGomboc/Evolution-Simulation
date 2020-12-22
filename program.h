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
    unsigned m_subprogram_pointer;
    std::vector<unsigned> m_instruction_pointers;
};

#endif // PROGRAM_H
