#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <vector>
#include <memory>

class Instruction
{
public:
    virtual ~Instruction() = 0;
    virtual void operator()(std::vector<float>& memory, unsigned& subprogram_pointer, std::vector<unsigned>& instruction_pointers) const = 0;
};

#endif // INSTRUCTION_H
