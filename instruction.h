#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <vector>
#include <memory>

class Instruction
{
public:
    virtual ~Instruction() = 0;
    virtual void operator()(std::vector<float>& memory, unsigned short& subprogram_pointer, std::vector<unsigned short>& instruction_pointers, std::vector<unsigned short>& return_pointers) const = 0;
protected:
    static float clamp(float value);
};

#endif // INSTRUCTION_H
