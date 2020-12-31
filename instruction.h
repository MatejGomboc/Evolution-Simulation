#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <vector>
#include <memory>
#include <string>
#include <unordered_map>

class Instruction
{
public:
    virtual ~Instruction() = 0;
    static std::unique_ptr<Instruction> fromStringTokens(const std::vector<std::string>& tokens);
    virtual void operator()(std::vector<float>& memory, unsigned char& subprogram_pointer,
        std::vector<unsigned short>& instruction_pointers, std::vector<unsigned char>& return_pointers) const = 0;
    virtual std::vector<std::string> toStringTokens() const = 0;

protected:
    typedef std::unique_ptr<Instruction> (*fromStringTokensSpecific_t)(const std::vector<std::string>& tokens);
    static const std::unordered_map<std::string, fromStringTokensSpecific_t> FACTORIES_TABLE;
    static float clamp(float value);
    static bool stringToUnsignedShort(const std::string& str, unsigned short& res);
    static bool stringToFloat(const std::string& str, float& res);
    static bool stringToUnsignedChar(const std::string& str, unsigned char& res);
};

#endif // INSTRUCTION_H
