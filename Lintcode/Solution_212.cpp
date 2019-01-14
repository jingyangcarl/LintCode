#include "Solution_212.h"

int Solution_212::replaceBlank(char string[], int length) {
	// write your code here
	if (string) string = NULL;
	std::string res(3 * length, 0);
	int spaceLen(0);
	for (int i = 0; i < length; i++) {
		if (string[i] == (int)' ') {
			res[i + spaceLen * 2] = '%';
			res[i + spaceLen * 2 + 1] = '2';
			res[i + spaceLen * 2 + 2] = '0';
			spaceLen++;
		}
		else {
			res[i + spaceLen * 2] = string[i];
		}
	}
	strcpy(string, res.c_str());
	return length + spaceLen * 2;
}

void Solution_212::test() {
	// write your test here

	// input
	string str;
	getline(cin, str);
	char * s = _strdup(str.c_str());

	// algorithm and output 
	cout << replaceBlank(s, str.size());
}
