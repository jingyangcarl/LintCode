#include "Solution_407.h"

vector<int> Solution_407::plusOne(vector<int>& digits) {
	// write your code here
	
	vector<int> newDigits;
	bool carry(true);
	for (int i = digits.size() - 1; i >= 0; i--) {
		if (digits[i] + carry >= 10) {
			newDigits.push_back((digits[i] + carry) % 10);
			carry = true;
		}
		else {
			newDigits.push_back(digits[i] + carry);
			carry = false;
		}
	}
	if (carry) newDigits.push_back(carry);

	reverse(newDigits.begin(), newDigits.end());
	return newDigits;
}

void Solution_407::test() {
	// write your test here

	// input
	vector<int> digits;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		digits.push_back(num);
	}

	// algorithm;
	digits = plusOne(digits);

	// output
	for (int i = 0; i < digits.size(); i++)
		cout << digits[i] << ' ';
}
