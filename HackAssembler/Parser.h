// This is the parsing portion of the Hack assembler

// To use, the user should load the constructtor with a pointer to an ifstream holding the file they wish to read from
// Then they run advance as long as hasMoreCommands is true
// Then, the symbol, dest, comp and jump functions should be used depending on what the result of getCurrentCommandType is

// It acts on commands that are of the following forms
// A_COMMAND @var or @num
// C_COMMAND dest=comp or comp;jump, where the first sets dest as a value, and the second jumps to a location if comp is valid
// L_COMMAND (LOCATION)

#pragma once
#include <fstream>
#include <string>
#include <memory>

class Parser {
public:
	enum class CommandType { A_COMMAND, C_COMMAND, L_COMMAND, NONE };
private:
	std::unique_ptr<std::ifstream> assemblyFileStream;
	std::string currentLine;
	CommandType currentCommandType;
	const char C_JMP_SPLIT = ';';
	const char C_DEST_SPLIT = '=';
public:
	Parser(std::ifstream *file);

	// File movement functions
	// Returns true if there are more lines in the assemblyFileStream
	bool hasMoreCommands();

	// gets the next commands if assemblyFileStream
	// strips their whitespace
	// skips to next command if it is a comment
	void advance();

	// Command information functions
	//  Gets the type of the current command, represented by the enum CommandType
	CommandType getCurrentCommandType();
	//  Returns the symbol portion of the command, should only be used if the command is A_COMMAND or L_COMMAND
	//  This returns the portion between parenthesis, or after an @
	std::string symbol();
	//  Returns the destination portion of the command, should only be used if the command is a C_COMMAND
	//  Returns before the =, if applicable, or an empty string otherwise
	std::string dest();
	// Returns the computation portion of the command, should only be used if the command is a C_COMMAND
	// Returns the portion after the =, or before the ;, in a C_COMMAND
	std::string comp();
	// Returns the jump portion of the command, should only be used if the command is a C_COMMAND
	// Returns the portion after the ;, if applicable, or an empty string otherwise
	std::string jump();
};