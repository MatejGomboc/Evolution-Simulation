#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <vector>
#include <memory>
#include <string>

class Instruction
{
public:
    virtual ~Instruction() = 0;
    static std::unique_ptr<Instruction> fromStringTokens(const std::vector<std::string>& tokens);
    virtual std::vector<std::string> toStringTokens() const = 0;
    virtual void operator()(std::vector<float>& memory, unsigned char& subprogram_pointer,
        std::vector<unsigned short>& instruction_pointers, std::vector<unsigned char>& return_pointers) const = 0;

protected:
    static float clamp(float value);
};

#endif // INSTRUCTION_H
