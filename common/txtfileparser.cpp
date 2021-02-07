#include <sstream>
#include <algorithm>
#include "txtfileparser.h"

size_t TxtFileParser::subprogramFromTxt(const std::string& text, std::vector<std::unique_ptr<Instruction>>& subprogram)
{
    subprogram.clear();
    std::stringstream text_stream(text);
    std::string line;
    size_t line_num = 1;

    while (std::getline(text_stream, line)) {
        std::vector<std::string> tokens;
        std::stringstream line_stream(line);
        std::string token;

        while (std::getline(line_stream, token, ' '))
        {
            token.erase(std::remove_if(token.begin(), token.end(), [](uint8_t c) { return std::isspace(c); }), token.end());
            if (!token.empty()) {
                tokens.push_back(token);
            }
        }

        subprogram.push_back(Instruction::fromStringTokens(tokens));
        if (subprogram.back() == nullptr) {
            subprogram.clear();
            return line_num;
        }

        line_num++;
    }

    return STATUS_SUCCESS;
}

std::string TxtFileParser::subprogramToTxt(const std::vector<std::unique_ptr<Instruction>>& subprogram)
{
    std::string text;

    for (const std::unique_ptr<Instruction>& instruction : subprogram) {
        std::vector<std::string> tokens = instruction->toStringTokens();
        for (const std::string& token : tokens) {
            text += '\n' + token + ' ';
        }
        text.pop_back();
    }

    return text;
}
