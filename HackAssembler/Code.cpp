#include "Code.h"

std::vector<unsigned int> Code::dest(const std::string& command) {
	if (command.compare("M") == 0) {
		return std::vector<unsigned int>{ 0, 0, 1 };
	}
	else if (command.compare("D") == 0) {
		return std::vector<unsigned int>{ 0, 1, 0 };
	}
	else if (command.compare("MD") == 0) {
		return std::vector<unsigned int>{ 0, 1, 1 };
	}
	else if (command.compare("A") == 0) {
		return std::vector<unsigned int>{ 1, 0, 0 };
	}
	else if (command.compare("AM") == 0) {
		return std::vector<unsigned int>{ 1, 0, 1 };
	}
	else if (command.compare("AD") == 0) {
		return std::vector<unsigned int>{ 1, 1, 0 };
	}
	else if (command.compare("AMD") == 0) {
		return std::vector<unsigned int>{ 1, 1, 1 };
	}
	else {
		return std::vector<unsigned int>{ 0, 0, 0 };
	}
}


std::vector<unsigned int> Code::comp(const std::string& command) {
	if (command.compare("0") == 0) {
		return std::vector<unsigned int>{1, 0, 1, 0, 1, 0};
	}
	else if (command.compare("1") == 0) {
		return std::vector<unsigned int>{1, 1, 1, 1, 1, 1};
	}
}


std::vector<unsigned int> Code::jump(const std::string& command) {
	if (command.compare("JGT") == 0) {
		return std::vector<unsigned int>{ 0, 0, 1 };
	}
	else if (command.compare("JEQ") == 0) {
		return std::vector<unsigned int>{ 0, 1, 0 };
	}
	else if (command.compare("JGE") == 0) {
		return std::vector<unsigned int>{ 0, 1, 1 };
	}
	else if (command.compare("JLT") == 0) {
		return std::vector<unsigned int>{ 1, 0, 0 };
	}
	else if (command.compare("JNE") == 0) {
		return std::vector<unsigned int>{ 1, 0, 1 };
	}
	else if (command.compare("JLE") == 0) {
		return std::vector<unsigned int>{ 1, 1, 0 };
	}
	else if (command.compare("JMP") == 0) {
		return std::vector<unsigned int>{ 1, 1, 1 };
	}
	else {
		return std::vector<unsigned int>{ 0, 0, 0 };
	}
}
