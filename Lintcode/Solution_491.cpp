#include "Solution_491.h"

bool Solution_491::isPalindrome(int num) {

	vector<char> digits;
	while (num) {
		digits.push_back(num % 10);
		num /= 10;
	}

	for (int i = 0; i < digits.size() / 2; i++) {
		if (digits[i] != digits[digits.size() - 1 - i])
			return false;
	}

	return true;
}

void Solution_491::test() {
	// write your test here

	// input
	int num;
	cin >> num;

	// algorithm and output
	cout << isPalindrome(num);
}
