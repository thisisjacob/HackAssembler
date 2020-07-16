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
        if (asmParser.getCurrentCommandType() == Parser::CommandType::A_COMMAND) {
            ++romVal;
        }
        else if (asmParser.getCurrentCommandType() == Parser::CommandType::L_COMMAND) {
            if (!symbols.contains(asmParser.symbol())) {
                symbols.addEntry(asmParser.symbol(), romVal);
            }
            ++romVal;
        }
        else if (asmParser.getCurrentCommandType() == Parser::CommandType::C_COMMAND) {
            ++romVal;
        }

    }
    file->seekg(0);


    // goes through each line of the file, converting it into machine code
    int ramAddress = 16;
    while (asmParser.hasMoreCommands()) {
        asmParser.advance();
        if (asmParser.getCurrentCommandType() == Parser::CommandType::A_COMMAND) {
            // reference to a location variable
            if (symbols.contains(asmParser.symbol())) {
                std::bitset<15> referenceBits(symbols.getAddress(asmParser.symbol()));
                output << "0" << referenceBits << std::endl;
            }
            // direct reference to an address
            else if (Utilities::isStringInteger(asmParser.symbol())) {
                std::bitset<15> referenceBits(std::stoi(asmParser.symbol()));
                output << "0" << referenceBits << std::endl;
            }
            // must be an undefined variable, so define it
            else { 
                symbols.addEntry(asmParser.symbol(), ramAddress);
                ++ramAddress;
            }
        }
        // comp command
        else if (asmParser.getCurrentCommandType() == Parser::CommandType::C_COMMAND) {
            output << "111" << Code::comp(asmParser.comp()) << Code::dest(asmParser.dest()) << Code::jump(asmParser.jump()) << std::endl;
        }
    }

    file->close();
    output.close();
    return 0;
}


