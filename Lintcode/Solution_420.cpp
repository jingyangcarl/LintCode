#include "Solution_420.h"

string Solution_420::countAndSay(int n) {
	// write your code here
	string result("1");

	for (int i = 1; i < n; i++) {
		string current;
		int count(0), entry(0);
		for (int j = 0; j < result.size(); j++) {
			if (entry == result[j]) {
				count++;
			}
			else {
				current += count == 0 ? "" : to_string(count) + (char)entry;
				entry = result[j];
				count = 1;
			}
		}
		current += to_string(count) + (char)entry;
		result = current;
	}

	return result;
}

void Solution_420::test() {
	// write your test here

	// intput
	int n;
	cin >> n;

	// algorithm and output
	cout << countAndSay(n);
}
