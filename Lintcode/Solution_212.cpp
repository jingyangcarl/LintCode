#include "Solution_212.h"

int Solution_212::replaceBlank(char string[], int length) {
	// write your code here
	char *res = new char[3 * length];
	int spaceLen(0);
	for (int i = 0; i < length; i++) {
		if (string[i] == (int)' ') {
			spaceLen++;
			res[i + spaceLen*3] = '%';
			res[i + spaceLen * 3 + 1] = '2';
			res[i + spaceLen * 3 + 2] = '0';
		}
		else {
			res[i] = string[i];
		}
	}
	string = res;
	return length + spaceLen * 2;
}

void Solution_212::test() {
	// write your test here

	// input
	string str;
	cin >> str;
	char * s = strdup(str.c_str());

	// algorithm and output 
	cout << replaceBlank(s, str.size());
}
