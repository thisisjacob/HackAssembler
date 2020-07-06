#pragma once
#include <utility>
#include <string>
#include <map>

static class Code {
private:
	std::map<std::string&, unsigned int&> compMap;
	std::map<std::string&, unsigned int&> destMap;
	std::map<std::string&, unsigned int&> jumpMap;
public:
	Code();
	// returns 3 0/1 bits representing the destination portion of a command
	unsigned int& dest();
	// returns 7 0/1 bits representing the computation portion of a command
	unsigned int& comp();
	// returns 3 0/1 bits representing the jump portion of a command
	unsigned int& jump();
};