#include "Solution_157.h"

bool Solution_157::isUnique(string & str) {
	// write your code here

	vector<int> charVec(256, 0);
	for (int i = 0; i < str.length(); i++) {
		if (charVec[str[i]] == 1) return false;
		else charVec[str[i]]++;
	}

	return true;
}

void Solution_157::test() {
	// write your test here

	// input
	string s;
	cin >> s;

	// algorithm and output
	cout << isUnique(s);
}
