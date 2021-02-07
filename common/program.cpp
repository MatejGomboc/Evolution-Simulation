#include "program.h"
#include "nop.h"

Program Program::generateRandom()
{
    Program program;
    // TODO !!!
    return program;
}

Program::Program()
{
    m_subprograms.push_back(std::vector<std::unique_ptr<Instruction>>());
    m_subprograms[0].push_back(std::make_unique<Nop>());

    m_instruction_pointers.push_back(0);
}

void Program::execute()
{
    (*m_subprograms[m_subprogram_pointer][m_instruction_pointers[m_subprogram_pointer]])(m_memory, m_subprogram_pointer, m_instruction_pointers, m_return_pointers);

    if (m_instruction_pointers[m_subprogram_pointer] == m_subprograms[m_subprogram_pointer].size()) {
        m_instruction_pointers[m_subprogram_pointer] = 0;
    }
}
