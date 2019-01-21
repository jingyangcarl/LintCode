#include "Solution_422.h"

int Solution_422::lengthOfLastWord(string & s) {
	// write your code here

	int lastLength(0);
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] != ' ') lastLength++;
		else if (lastLength != 0) return lastLength;
	}

	return lastLength;
}

void Solution_422::test() {
	// write your test here

	// input
	string str;
	cin >> str;

	// algorithm and output
	cout << lengthOfLastWord(str) << endl;
}