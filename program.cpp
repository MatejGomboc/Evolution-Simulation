#include "program.h"

void Program::execute()
{
    (*m_subprograms[m_subprogram_pointer][m_instruction_pointers[m_subprogram_pointer]])(m_memory, m_subprogram_pointer, m_instruction_pointers);

    if (m_instruction_pointers[m_subprogram_pointer] == m_subprograms[m_subprogram_pointer].size()) {
        m_instruction_pointers[m_subprogram_pointer] = 0;
    }
}
