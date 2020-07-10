#include "Code.h"

std::string Code::dest(const std::string& command) {
	if (command.compare("M") == 0) {
		return std::string("001");
	}
	else if (command.compare("D") == 0) {
		return std::string("010");
	}
	else if (command.compare("MD") == 0) {
		return std::string("011");
	}
	else if (command.compare("A") == 0) {
		return std::string("100");
	}
	else if (command.compare("AM") == 0) {
		return std::string("101");
	}
	else if (command.compare("AD") == 0) {
		return std::string("110");
	}
	else if (command.compare("AMD") == 0) {
		return std::string("111");
	}
	else {
		return std::string("000");
	}
}


std::string Code::comp(const std::string& command) {
	if (command.compare("0") == 0) {
		return std::string("0101010");
	}
	else if (command.compare("1") == 0) {
		return std::string("0111111");
	}
	else if (command.compare("-1") == 0) {
		return std::string("0111010");
	}
	else if (command.compare("D") == 0) {
		return std::string("0001100");
	}
	else if (command.compare("A") == 0) {
		return std::string("0110000");
	}
	else if (command.compare("!D") == 0) {
		return std::string("0001101");
	}
	else if (command.compare("!A") == 0) {
		return std::string("0110001");
	}
	else if (command.compare("-D") == 0) {
		return std::string("0001111");
	}
	else if (command.compare("-A") == 0) {
		return std::string("0110011");
	}
	else if (command.compare("D+1") == 0) {
		return std::string("0011111");
	}
	else if (command.compare("A+1") == 0) {
		return std::string("0110111");
	}
	else if (command.compare("D-1") == 0) {
		return std::string("0001110");
	}
	else if (command.compare("A-1") == 0) {
		return std::string("0110010");
	}
	else if (command.compare("D+A") == 0) {
		return std::string("0000010");
	}
	else if (command.compare("D-A") == 0) {
		return std::string("0010011");
	}
	else if (command.compare("A-D") == 0) {
		return std::string("0000111");
	}
	else if (command.compare("D&A") == 0) {
		return std::string("0000000");
	}
	else if (command.compare("D|A") == 0) {
		return std::string("0010101");
	}
	else if (command.compare("M") == 0) {
		return std::string("1110000");
	}
	else if (command.compare("!M") == 0) {
		return std::string("1110001");
	}
	else if (command.compare("-M") == 0) {
		return std::string("1110011");
	}
	else if (command.compare("M+1") == 0) {
		return std::string("1110111");
	}
	else if (command.compare("M-1") == 0) {
		return std::string("1110010");
	}
	else if (command.compare("D+M") == 0) {
		return std::string("1000010");
	}
	else if (command.compare("D-M") == 0) {
		return std::string("1010011");
	}
	else if (command.compare("M-D") == 0) {
		return std::string("1000111");
	}
	else if (command.compare("D&M") == 0) {
		return std::string("1000000");
	}
	else if (command.compare("D|M") == 0) {
		return std::string("1010101");
	}
}


std::string Code::jump(const std::string& command) {
	if (command.compare("JGT") == 0) {
		return std::string("001");
	}
	else if (command.compare("JEQ") == 0) {
		return std::string("010");
	}
	else if (command.compare("JGE") == 0) {
		return std::string("011");
	}
	else if (command.compare("JLT") == 0) {
		return std::string("100");
	}
	else if (command.compare("JNE") == 0) {
		return std::string("101");
	}
	else if (command.compare("JLE") == 0) {
		return std::string("110");
	}
	else if (command.compare("JMP") == 0) {
		return std::string("111");
	}
	else {
		return std::string("000");
	}
}
