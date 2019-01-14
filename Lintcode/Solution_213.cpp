#include "Solution_213.h"

string Solution_213::compress(string & originalString) {
	// write your code here
	if (originalString.size() == 0) return originalString;
	int currentChar(0), count(0);
	string res;
	res.push_back(originalString[0]);
	currentChar = originalString[0];
	for (int i = 1; i < originalString.size(); i++) {
		if (originalString[i] != currentChar) {
			// add summary for the last char
			res += to_string(count);
			// update currentChar
			currentChar = originalString[i];
			res.push_back((char)currentChar);
			count = 1;
		}
		else count++;
	}

	return originalString = originalString.size() < res.size() ? originalString : res;
}

void Solution_213::test() {
	// write your test here

	// input
	string str;
	cin >> str;

	// output and algorithm
	cout << compress(str);
}
