#pragma once
#include <utility>
#include <string>
#include <vector>
#include <map>

static class Code {
public:
	// returns 3 0/1 bits representing the destination portion of a command
	static std::string dest(const std::string& command);
	// returns 7 0/1 bits representing the computation portion of a command
	static std::string comp(const std::string& command);
	// returns 3 0/1 bits representing the jump portion of a command
	static std::string jump(const std::string& command);
};