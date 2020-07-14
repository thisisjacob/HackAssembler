#include <iostream>
#include <fstream>
#include <bitset>
#include "Parser.h"
#include "Code.h"

int main(int argc, char* argv[], char* envp[])
{
    std::string fileName = argv[1];
    std::ifstream* file = new std::ifstream(fileName); // test value
    int extensionLocation = fileName.find('.');
    std::ofstream output = std::ofstream(fileName.substr(0, extensionLocation) + ".hack");
    


    Parser asmParser = Parser(file);
    while (asmParser.hasMoreCommands()) {
        asmParser.advance();
        if (asmParser.getCurrentCommandType() == Parser::CommandType::A_COMMAND) {
            std::bitset<15> referenceBits (std::stoi(asmParser.symbol()));
            output << "0" << referenceBits << std::endl;
        }
        else if (asmParser.getCurrentCommandType() == Parser::CommandType::C_COMMAND) {
            output << "111" << Code::comp(asmParser.comp()) << Code::dest(asmParser.dest()) << Code::jump(asmParser.jump()) << std::endl;
        }
        else if (asmParser.getCurrentCommandType() == Parser::CommandType::L_COMMAND) {

        }
    }
    file->close();
    output.close();
    return 0;
}
