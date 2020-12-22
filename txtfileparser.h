#ifndef TXTFILEPARSER_H
#define TXTFILEPARSER_H

#include <string>
#include "instruction.h"

namespace TxtFileParser
{
    size_t subprogramFromTxt(const std::string& text, std::vector<std::unique_ptr<Instruction>>& subprogram);
    std::string subprogramToTxt(const std::vector<std::unique_ptr<Instruction>>& subprogram);
};

#endif // TXTFILEPARSER_H
