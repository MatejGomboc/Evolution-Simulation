#ifndef TXTFILEPARSER_H
#define TXTFILEPARSER_H

#include "instruction.h"

class TxtFileParser
{
public:
    static constexpr size_t STATUS_SUCCESS = 0;
    static size_t subprogramFromTxt(const std::string& text, std::vector<std::unique_ptr<Instruction>>& subprogram);
    static std::string subprogramToTxt(const std::vector<std::unique_ptr<Instruction>>& subprogram);

private:
    TxtFileParser() = delete;
    ~TxtFileParser() = delete;
};

#endif // TXTFILEPARSER_H
