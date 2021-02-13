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
    uint8_t subprogram_index = 0;

    switch (Utils::generateRandomInt(0, 3)) {
    case 0:
        program.addNop(subprogram_index);
        break;
    case 1:
        program.addRandomInit(subprogram_index, true);
        break;
    case 2:
        if (program.m_memory.empty()) {
            break;
        }
        program.addRandomCopy(subprogram_index, true, 0);
        break;
    case 3:
        if (program.m_memory.empty()) {
            break;
        }
        program.addRandomMathLogicInstruction(subprogram_index, true, 0);
        break;
    }

    return program;
}

Program::Program()
{
    m_subprograms.push_back(std::vector<std::unique_ptr<Instruction>>());
    m_subprograms[0].push_back(std::make_unique<Nop>());

    m_instruction_addresses.push_back(0);
}

void Program::execute()
{
    (*m_subprograms[m_subprogram_index][m_instruction_addresses[m_subprogram_index]])(m_memory, m_subprogram_index, m_instruction_addresses, m_return_addresses);

    if (m_instruction_addresses[m_subprogram_index] == m_subprograms[m_subprogram_index].size()) {
        m_instruction_addresses[m_subprogram_index] = 0;
    }
}

uint16_t Program::generateRandomMemoryAddress(bool adding_allowed, uint16_t max_allowed_memory)
{
    if (adding_allowed && ((max_allowed_memory == 0) || (m_memory.size() < max_allowed_memory)) && Utils::generateRandomBool()) {
        m_memory.push_back(generateRandomMemoryValue());
        return static_cast<uint16_t>(m_memory.size() - 1);
    } else {
        if (m_memory.size() < 2) {
            return 0;
        } else {
            return static_cast<uint16_t>(Utils::generateRandomInt(0, m_memory.size() - 1));
        }
    }
}

int32_t Program::generateRandomMemoryValue()
{
    return static_cast<int32_t>(Utils::generateRandomInt(-std::numeric_limits<int32_t>::max(), std::numeric_limits<int32_t>::max()));
}

void Program::addNop(uint8_t subprogram_index)
{
    m_subprograms[subprogram_index].push_back(std::make_unique<Nop>());
}

void Program::addRandomInit(uint8_t subprogram_index, bool adding_memory_allowed, uint16_t max_allowed_memory)
{
    uint16_t output_memory_address = generateRandomMemoryAddress(adding_memory_allowed, max_allowed_memory);
    m_subprograms[subprogram_index].push_back(std::make_unique<Init>(generateRandomMemoryValue(), output_memory_address));
}

void Program::addRandomCopy(uint8_t subprogram_index, bool adding_memory_allowed, uint16_t max_allowed_memory)
{
    uint16_t input_memory_address = generateRandomMemoryAddress(false);
    uint16_t output_memory_address = generateRandomMemoryAddress(adding_memory_allowed, max_allowed_memory);
    m_subprograms[subprogram_index].push_back(std::make_unique<Copy>(input_memory_address, output_memory_address));
}

void Program::addRandomMathLogicInstruction(uint8_t subprogram_index, bool adding_memory_allowed, uint16_t max_allowed_memory)
{
    uint8_t selection = static_cast<uint8_t>(Utils::generateRandomInt(0, 12));

    uint16_t input1_memory_address = generateRandomMemoryAddress(false);
    uint16_t input2_memory_address;
    if (selection > 3) {
        input2_memory_address = generateRandomMemoryAddress(false);
    }
    uint16_t output_memory_address = generateRandomMemoryAddress(adding_memory_allowed, max_allowed_memory);

    switch (selection) {
    case 0:
        m_subprograms[subprogram_index].push_back(std::make_unique<Add>(input1_memory_address, input2_memory_address, output_memory_address));
    case 1:
        m_subprograms[subprogram_index].push_back(std::make_unique<And>(input1_memory_address, input2_memory_address, output_memory_address));
    case 2:
        m_subprograms[subprogram_index].push_back(std::make_unique<Decrease>(input1_memory_address, output_memory_address));
    case 3:
        m_subprograms[subprogram_index].push_back(std::make_unique<Divide>(input1_memory_address, input2_memory_address, output_memory_address));
    case 4:
        m_subprograms[subprogram_index].push_back(std::make_unique<Equal>(input1_memory_address, input2_memory_address, output_memory_address));
    case 5:
        m_subprograms[subprogram_index].push_back(std::make_unique<Greater>(input1_memory_address, input2_memory_address, output_memory_address));
    case 6:
        m_subprograms[subprogram_index].push_back(std::make_unique<Increase>(input1_memory_address, output_memory_address));
    case 7:
        m_subprograms[subprogram_index].push_back(std::make_unique<Multiply>(input1_memory_address, input2_memory_address, output_memory_address));
    case 8:
        m_subprograms[subprogram_index].push_back(std::make_unique<Negate>(input1_memory_address, output_memory_address));
    case 9:
        m_subprograms[subprogram_index].push_back(std::make_unique<Not>(input1_memory_address, output_memory_address));
    case 10:
        m_subprograms[subprogram_index].push_back(std::make_unique<Or>(input1_memory_address, input2_memory_address, output_memory_address));
    case 11:
        m_subprograms[subprogram_index].push_back(std::make_unique<Smaller>(input1_memory_address, input2_memory_address, output_memory_address));
    default:
        m_subprograms[subprogram_index].push_back(std::make_unique<Subtract>(input1_memory_address, input2_memory_address, output_memory_address));
    }
}
