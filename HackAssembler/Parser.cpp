#include "Parser.h"

Parser::Parser(std::ifstream *file) {
	assemblyFileStream = std::unique_ptr<std::ifstream>(file);
}

bool Parser::hasMoreCommands() {
	return (assemblyFileStream->peek() != EOF);
}

void Parser::advance() {
	std::getline(*assemblyFileStream, currentLine);
	// removes comments
	if (currentLine.find("//") != std::string::npos) {
		currentLine = currentLine.substr(0, currentLine.find("//"));
	}
	// strips whitespace
	currentLine.erase(remove(currentLine.begin(), currentLine.end(), ' '), currentLine.end());
	currentLine.erase(remove(currentLine.begin(), currentLine.end(), '\t'), currentLine.end());
	currentLine.erase(remove(currentLine.begin(), currentLine.end(), '\n'), currentLine.end());



	currentCommandType = commandType();

	// skips to next command if current command is a comment and there is another command to retrieve
	if (currentLine.size() >= 2 && currentLine[0] == '/' && currentLine[1] == '/'
		&& hasMoreCommands()) {
		advance();
	}
}

Parser::CommandType Parser::commandType() {
	if (currentLine[0] == '@') {
		return CommandType::A_COMMAND;
	}
	else if (currentLine[0] == '(' && currentLine[currentLine.length() - 1] == ')') {
		return CommandType::L_COMMAND;
	}
	else if (currentLine.find('/') == std::string::npos){
		return CommandType::C_COMMAND;
	}
	else {
		return CommandType::NONE;
	}
}

std::string Parser::symbol() {
	if (currentLine.size() == 0) {
		return "";
	}
	if (currentCommandType == CommandType::A_COMMAND) {
		return currentLine.substr(1, std::string::npos);
	}
	else {
		return currentLine.substr(1, currentLine.length() - 2);
	}
}

std::string Parser::dest() {
	if (currentLine.size() == 0) {
		return "";
	}
	// if this includes a dest portion, return up to the equal sign in currentLine
	if (currentLine.find(C_DEST_SPLIT) != std::string::npos) {
		return currentLine.substr(0, currentLine.find('='));
	}
	return ""; 
}

std::string Parser::comp() {
	if (currentLine.size() == 0) {
		return "";
	}
	else if (currentLine.find(C_JMP_SPLIT) != std::string::npos) {
		return currentLine.substr(0, currentLine.find(C_JMP_SPLIT));
	}
	else if (currentLine.find(C_DEST_SPLIT) != std::string::npos) {
		return currentLine.substr(currentLine.find(C_DEST_SPLIT) + 1, currentLine.length());
	}
	return ""; 
}

std::string Parser::jump() {
	if (currentLine.size() == 0) {
		return "";
	}
	else if (currentLine.find(C_JMP_SPLIT) != std::string::npos) {
		return currentLine.substr(currentLine.find(C_JMP_SPLIT) + 1, std::string::npos);
	}
	return "";
}