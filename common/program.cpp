#include "program.h"
#include "utils.h"
#include "add.h"
#include "and.h"
#include "condition.h"
#include "copy.h"
#include "decrease.h"
#include "divide.h"
#include "equal.h"
#include "greater.h"
#include "increase.h"
#include "init.h"
#include "loop.h"
#include "multiply.h"
#include "negate.h"
#include "nop.h"
#include "not.h"
#include "or_.h"
#include "return.h"
#include "smaller.h"
#include "subtract.h"

Program Program::random()
{
    Program program;
    uint8_t subprogram_pointer = 0;

    switch (Utils::generateRandomInt(0, 3)) {
    case 0:
        program.m_subprograms[subprogram_pointer].push_back(std::make_unique<Nop>());
        break;
    case 1: {
        uint16_t memory_pointer;
        if (program.m_memory.empty() || Utils::generateRandomBool()) {
            program.m_memory.push_back(Utils::generateRandomFloat());
            memory_pointer = program.m_memory.size() - 1;
        } else {
            if (program.m_memory.size() < 2) {
                memory_pointer = 0;
            } else {
                memory_pointer = Utils::generateRandomInt(0, program.m_memory.size() - 1);
            }
        }

        program.m_subprograms[subprogram_pointer].push_back(std::make_unique<Init>(Utils::generateRandomFloat(), memory_pointer));
        break;
    }
    }

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

std::unique_ptr<Instruction> Program::randomArithmeticalLogicalInstruction(uint16_t input_pointer, uint16_t output_pointer)
{
    switch (Utils::generateRandomInt(0, 3)) {
    case 0:
        return std::make_unique<Decrease>(input_pointer, output_pointer);
    case 1:
        return std::make_unique<Increase>(input_pointer, output_pointer);
    case 2:
        return std::make_unique<Negate>(input_pointer, output_pointer);
    default:
        return std::make_unique<Not>(input_pointer, output_pointer);
    }
}

std::unique_ptr<Instruction> Program::randomArithmeticalLogicalInstruction(uint16_t input1_pointer, uint16_t input2_pointer, uint16_t output_pointer)
{
    switch (Utils::generateRandomInt(0, 8)) {
    case 0:
        return std::make_unique<Add>(input1_pointer, input2_pointer, output_pointer);
    case 1:
        return std::make_unique<And>(input1_pointer, input2_pointer, output_pointer);
    case 2:
        return std::make_unique<Divide>(input1_pointer, input2_pointer, output_pointer);
    case 3:
        return std::make_unique<Equal>(input1_pointer, input2_pointer, output_pointer);
    case 4:
        return std::make_unique<Greater>(input1_pointer, input2_pointer, output_pointer);
    case 5:
        return std::make_unique<Multiply>(input1_pointer, input2_pointer, output_pointer);
    case 6:
        return std::make_unique<Or>(input1_pointer, input2_pointer, output_pointer);
    case 7:
        return std::make_unique<Smaller>(input1_pointer, input2_pointer, output_pointer);
    default:
        return std::make_unique<Subtract>(input1_pointer, input2_pointer, output_pointer);
    }
}
