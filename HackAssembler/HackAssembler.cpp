// This program takes the Assembly code for the CPU specified in the book "The Elements of Computing Systems"
// And returns its machine code equivalent
// It must be run from the command line with an argument pointing to a [NAME].asm file
// It then returns a file named [NAME].hack, which holds the machine code

#include <iostream>
#include <fstream>
#include <bitset>
#include "Parser.h"
#include "Code.h"

int main(int argc, char* argv[], char* envp[])
{
    // initializes the program
    std::string fileName = argv[1];
    std::ifstream* file = new std::ifstream(fileName); // test value
    int extensionLocation = fileName.find('.');
    std::ofstream output = std::ofstream(fileName.substr(0, extensionLocation) + ".hack");
    Parser asmParser = Parser(file);


    // goes through each line of the file, converting it into machine code
    while (asmParser.hasMoreCommands()) {
        asmParser.advance();
        // change memory location referenced command
        if (asmParser.getCurrentCommandType() == Parser::CommandType::A_COMMAND) {
            std::bitset<15> referenceBits(std::stoi(asmParser.symbol()));
            output << "0" << referenceBits << std::endl;
        }
        // comp command
        else if (asmParser.getCurrentCommandType() == Parser::CommandType::C_COMMAND) {
            output << "111" << Code::comp(asmParser.comp()) << Code::dest(asmParser.dest()) << Code::jump(asmParser.jump()) << std::endl;
        }
        // label command
        else if (asmParser.getCurrentCommandType() == Parser::CommandType::L_COMMAND) {

        }
    }

    file->close();
    output.close();
    return 0;
}
