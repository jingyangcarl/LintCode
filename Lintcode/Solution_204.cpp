#include "Solution_204.h"

Solution_204* Solution_204::instance = NULL;

Solution_204 * Solution_204::getInstance() {
	// write your code here
	return instance;
}

void Solution_204::test() {
	// write your test here
	getInstance();
}
