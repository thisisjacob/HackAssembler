#include "SymbolTable.h"

SymbolTable::SymbolTable() {
	symbolAddressMap = std::unordered_map<std::string, int>();
	symbolAddressMap.insert({ "SP", 0 });
	symbolAddressMap.insert({ "LCL", 1 });
	symbolAddressMap.insert({ "ARG", 2 });
	symbolAddressMap.insert({ "THIS", 3 });
	symbolAddressMap.insert({ "THAT", 4 });
	symbolAddressMap.insert({ "R0", 0 });
	symbolAddressMap.insert({ "R1", 1 });
	symbolAddressMap.insert({ "R2", 2 });
	symbolAddressMap.insert({ "R3", 3 });
	symbolAddressMap.insert({ "R4", 4 });
	symbolAddressMap.insert({ "R5", 5 });
	symbolAddressMap.insert({ "R6", 6 });
	symbolAddressMap.insert({ "R7", 7 });
	symbolAddressMap.insert({ "R8", 8 });
	symbolAddressMap.insert({ "R9", 9 });
	symbolAddressMap.insert({ "R10", 10 });
	symbolAddressMap.insert({ "R11", 11 });
	symbolAddressMap.insert({ "R12", 12 });
	symbolAddressMap.insert({ "R13", 13 });
	symbolAddressMap.insert({ "R14", 14 });
	symbolAddressMap.insert({ "R15", 15 });
	symbolAddressMap.insert({ "SCREEN", 16384 });
	symbolAddressMap.insert({ "KBD", 24576 });
}

void SymbolTable::addEntry(std::string symbol, int address) {
	symbolAddressMap.insert({ symbol, address });
}

bool SymbolTable::contains(std::string symbol) {
	return symbolAddressMap.find(symbol) != symbolAddressMap.end();
}

int SymbolTable::getAddress(std::string address) {
	return symbolAddressMap[address];
}