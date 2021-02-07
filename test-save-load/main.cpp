#include <iostream>
#include <fstream>
#include <streambuf>
#include "txtfileparser.h"

int main()
{
    const std::string file_names[] = { "s0.txt" };

    for (const std::string& file_name : file_names) {
        std::ifstream file(file_name, std::ios::binary);
        if (!file.is_open()) {
            std::cerr << "Cannot open file: " << file_name << std::endl;
            return -1;
        }

        file.seekg(0, std::ios::end);
        std::streampos file_size = file.tellg();
        file.seekg(0, std::ios::beg);

        std::string text(file_size, '\0');
        file.read(text.data(), text.size());
        file.close();

        /*std::vector<std::unique_ptr<Instruction>> subprogram;
        size_t status = TxtFileParser::subprogramFromTxt(text, subprogram);
        if (status != TxtFileParser::STATUS_SUCCESS) {
            std::cerr << "Error in file: " << file_name << std::endl;
            std::cerr << "Error at line: " << status << std::endl;
            return -2;
        }
        subprogram.clear();*/
    }

    std::cout << "Success" << std::endl;
    return 0;
}
