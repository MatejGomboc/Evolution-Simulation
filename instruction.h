#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <vector>
#include <memory>
#include <string>

class Instruction
{
public:
    static constexpr size_t MIN_NUM_TOKENS = 2;
    static constexpr size_t MAX_NUM_TOKENS = 4;

    virtual ~Instruction() = 0;
    static std::unique_ptr<Instruction> fromStringTokens(const std::vector<std::string>& tokens);
    virtual std::vector<std::string> toStringTokens() const = 0;
    virtual void operator()(std::vector<float>& memory, unsigned char& subprogram_pointer,
        std::vector<unsigned short>& instruction_pointers, std::vector<unsigned char>& return_pointers) const = 0;

protected:
    static float clamp(float value);
    virtual std::unique_ptr<Instruction> fromStringTokensSpecific(const std::vector<std::string>& tokens) const = 0;
};

#endif // INSTRUCTION_H
