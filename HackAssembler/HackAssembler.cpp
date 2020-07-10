#include <iostream>
#include <fstream>
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
        if (asmParser.commandType() == Parser::CommandType::A_COMMAND) {
            
        }
        if (asmParser.commandType() == Parser::CommandType::C_COMMAND) {
            //binaryCode = binaryCode + Code::comp(asmParser.comp()) + Code::dest(asmParser.dest()) + Code::jump(asmParser.jump());
            output << "111" << Code::comp(asmParser.comp()) << Code::dest(asmParser.dest()) << Code::jump(asmParser.jump()) << std::endl;
        }
        if (asmParser.commandType() == Parser::CommandType::L_COMMAND) {

        }
    }
    std::cin.get();
    file->close();
    output.close();
}
