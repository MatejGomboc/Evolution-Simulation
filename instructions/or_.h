#ifndef OR__H
#define OR__H

#include "instruction.h"

class Or : public Instruction
{
public:
    static const std::string MNEMONIC;
    Or(unsigned short input1_pointer, unsigned short input2_pointer, unsigned short output_pointer);
    void operator()(std::vector<float>& memory, unsigned char& subprogram_pointer, std::vector<unsigned short>& instruction_pointers,
        std::vector<unsigned char>& return_pointers) const override;
    std::vector<std::string> toStringTokens() const override;
    static std::unique_ptr<Instruction> fromStringTokens(const std::vector<std::string>& tokens);

private:
    unsigned short m_input1_pointer;
    unsigned short m_input2_pointer;
    unsigned short m_output_pointer;
};

#endif // OR__H
