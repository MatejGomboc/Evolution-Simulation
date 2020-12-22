#include <limits>
#include "divide.h"

Divide::Divide(unsigned input1_pointer, unsigned input2_pointer, unsigned output_pointer) :
    m_input1_pointer(input1_pointer),
    m_input2_pointer(input2_pointer),
    m_output_pointer(output_pointer)
{
}

void Divide::operator()(std::vector<float>& memory, unsigned& subprogram_pointer, std::vector<unsigned>& instruction_pointers) const
{
    if (memory[m_input2_pointer] == 0) {
        if (memory[m_input1_pointer] == 0) {
            memory[m_output_pointer] = 1;
        } else {
            if (memory[m_input1_pointer] > 0) {
                memory[m_output_pointer] = std::numeric_limits<float>::max();
            } else {
                memory[m_output_pointer] = std::numeric_limits<float>::min();
            }
        }
    } else {
        memory[m_output_pointer] = memory[m_input1_pointer] / memory[m_input2_pointer];
    }

    instruction_pointers[subprogram_pointer]++;
}
