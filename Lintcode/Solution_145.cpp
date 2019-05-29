#include "Solution_145.h"

char Solution_145::lowercaseToUppercase(char character) {
	// write your code here
	return character - ('a' - 'A');
}

void Solution_145::test() {
	// input
	char character;
	cin >> character;

	// algorithm and output
	cout << lowercaseToUppercase(character) << endl;
}
