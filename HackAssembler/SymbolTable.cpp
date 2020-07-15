#include "SymbolTable.h"

SymbolTable::SymbolTable() {
	symbolAddressMap = std::unordered_map<std::string, int>();
}

void SymbolTable::addEntry(std::string symbol, int address) {
	symbolAddressMap.insert({ symbol, address });
}

bool SymbolTable::contains(std::string symbol) {
	return symbolAddressMap.find(symbol) == symbolAddressMap.end();
}

int SymbolTable::getAddress(std::string address) {
	return symbolAddressMap[address];
}