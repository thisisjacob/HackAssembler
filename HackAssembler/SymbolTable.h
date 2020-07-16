#pragma once
#include <string>
#include <unordered_map>

class SymbolTable {
private:
	// Key is a command, int is its address
	std::unordered_map<std::string, int> symbolAddressMap;
public:
	// Initializes an empty SymbolTable
	// Adds the default symbols to storage
	SymbolTable();
	// Adds the entry symbol at the address in int
	void addEntry(std::string symbol, int address);
	// Returns true if the symbol is stored in this SymbolTable
	bool contains(std::string symbol);
	// Returns the address of the given symbol.
	// This must only ever be called if contains returned true.
	int getAddress(std::string symbol);
};