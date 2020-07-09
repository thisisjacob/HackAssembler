// HackAssembler.cpp : This file contains the 'main' function. Program execution begins and ends there.

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
    std::string currentLine;
    while (asmParser.hasMoreCommands()) {
        asmParser.advance();
        if (asmParser.commandType() == Parser::CommandType::A_COMMAND) {

        }
        if (asmParser.commandType() == Parser::CommandType::C_COMMAND) {

        }
        if (asmParser.commandType() == Parser::CommandType::L_COMMAND) {

        }
    }
    std::cin.get();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
