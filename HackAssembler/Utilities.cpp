#include "Utilities.h"

bool Utilities::isStringInteger(std::string item) {
	for (int i = 0; i < item.length(); i++) {
		if (!isdigit(item[i])) {
			return false;
		}
	}

	return true;
}