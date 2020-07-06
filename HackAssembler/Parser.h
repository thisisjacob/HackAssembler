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
	bool hasMoreCommands();
	// gets the next commands if assemblyFileStream
	// strips their whitespace
	// skips to next command if it is a comment
	void advance();
	// Command information functions
	CommandType commandType();
	std::string symbol();
	std::string dest();
	std::string comp();
	std::string jump();
};