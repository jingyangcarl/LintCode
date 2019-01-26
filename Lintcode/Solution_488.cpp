#include "Solution_488.h"

bool Solution_488::isHappy(int n) {
	// write your code here

	unordered_set<int> result;
	int current(n);
	while (current != 1) {
		int next(0);
		while (current) {
			next += (current % 10) * (current % 10);
			current /= 10;
		}

		if (result.find(next) == result.end())
			result.insert(next);
		else return false;

		current = next;
	}

	return true;
}

void Solution_488::test() {
	// write your test here

	// input
	int n;
	cin >> n;

	// algorithm and output
	cout << isHappy(n);
}
