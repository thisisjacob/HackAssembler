// This program takes the Assembly code for the CPU specified in the book "The Elements of Computing Systems"
// And returns its machine code equivalent
// It must be run from the command line with an argument pointing to a [NAME].asm file
// It then returns a file named [NAME].hack, which holds the machine code

// NOTE: This program will end if there is no .asm file loaded when called, or added to the debugger

#include <iostream>
#include <fstream>
#include <bitset>
#include "Parser.h"
#include "Code.h"
#include "SymbolTable.h"
#include "Utilities.h"

int main(int argc, char* argv[], char* envp[])
{
    // initializes the program
    std::string fileName = argv[1];
    std::ifstream* file = new std::ifstream(fileName); // test value
    int extensionLocation = fileName.find('.');
    std::ofstream output = std::ofstream(fileName.substr(0, extensionLocation) + ".hack");

    // first run for symbol-address association
    Parser asmParser = Parser(file);
    SymbolTable symbols = SymbolTable();
    int romVal = 0;
    while (asmParser.hasMoreCommands()) {
        asmParser.advance();
        // advance position in ROM if command is a variable reference
        if (asmParser.getCurrentCommandType() == Parser::CommandType::A_COMMAND) {
            ++romVal;
        }
        // if a label pseudocommand is at this line, do not advance ROM, associate new label variable with current ROM address
        else if (asmParser.getCurrentCommandType() == Parser::CommandType::L_COMMAND) {
            if (!symbols.contains(asmParser.symbol())) {
                symbols.addEntry(asmParser.symbol(), romVal);
            }
        }
        // advance position in ROM if command is a computation command
        else if (asmParser.getCurrentCommandType() == Parser::CommandType::C_COMMAND) {
            ++romVal;
        }

    }
    file->seekg(0);


    // goes through each line of the file, converting it into machine code
    int ramAddress = 16;
    while (asmParser.hasMoreCommands()) {
        asmParser.advance();
        // output a variant of a reference command
        if (asmParser.getCurrentCommandType() == Parser::CommandType::A_COMMAND) {
            // output a reference to a stored variable
            if (symbols.contains(asmParser.symbol())) {
                output << "0" << std::bitset<15>(symbols.getAddress(asmParser.symbol())) << std::endl;
            }
            // direct reference to an address
            else if (Utilities::isStringInteger(asmParser.symbol())) {
                output << "0" << std::bitset<15>(std::stoi(asmParser.symbol())) << std::endl;
            }
            // must be an undefined variable, so define it and then output its reference
            else { 
                symbols.addEntry(asmParser.symbol(), ramAddress);
                output << "0" << std::bitset<15>(symbols.getAddress(asmParser.symbol())) << std::endl;
                ++ramAddress;
            }
        }
        // output comp command
        else if (asmParser.getCurrentCommandType() == Parser::CommandType::C_COMMAND) {
            output << "111" << Code::comp(asmParser.comp()) << Code::dest(asmParser.dest()) << Code::jump(asmParser.jump()) << std::endl;
        }
    }

    file->close();
    output.close();
    return 0;
}


