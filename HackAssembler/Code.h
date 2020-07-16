// This class uses results from the comp, dest and jump returns from the Parser class
// Its purpose is to take those standard returned commands, and return the binary versions of those commands

#pragma once
#include <utility>
#include <string>
#include <vector>
#include <map>

class Code {
public:
	// Converts a dest command to binary
	// returns 3 0/1 bits representing the destination portion of a command
	static std::string dest(const std::string& command);
	// Converts a comp command to binary
	// returns 7 0/1 bits representing the computation portion of a command
	static std::string comp(const std::string& command);
	// Converts a jump command to binary
	// returns 3 0/1 bits representing the jump portion of a command
	static std::string jump(const std::string& command);
};