#pragma once
#include <utility>
#include <string>
#include <vector>

static class Code {
public:
	Code();
	// returns 3 0/1 bits representing the destination portion of a command
	std::vector<unsigned int> dest(const std::string& command);
	// returns 7 0/1 bits representing the computation portion of a command
	std::vector<unsigned int> comp(const std::string& command);
	// returns 3 0/1 bits representing the jump portion of a command
	std::vector<unsigned int> jump(const std::string& command);
};