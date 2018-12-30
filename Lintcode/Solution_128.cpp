#include "Solution_128.h"

int Solution_128::hashCode(string & key, int HASH_SIZE) {
	// write your code here

	int magic(33);
	int sum(0);
	
	for (int i = 0; i < key.size(); i++) {
		int currentChar = (int)key[i];
		int currentFactor(1);
		for (int j = key.size() - i - 1; j > 0; j--) currentFactor *= magic;
		sum += currentFactor * currentChar;
	}
	return sum % HASH_SIZE;
}

void Solution_128::test() {
	// write your test here
	
	// input
	string key;
	cin >> key;
	int HASH_SIZE;
	cin >> HASH_SIZE;

	// algorithm and output
	cout << hashCode(key, HASH_SIZE);
}
