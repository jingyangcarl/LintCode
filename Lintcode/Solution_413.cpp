#include "Solution_413.h"

int Solution_413::reverseInteger(int n) {
	// write your code here

	bool positive(n >= 0 ? true : false);
	string s;
	while (abs(n) > 0) {
		s += (abs(n) % 10) + '0';
		n /= 10;
	}
	long long reverseNum = atoll(s.c_str());
	if (reverseNum > UINT32_MAX) return 0;

	return positive ? reverseNum : -reverseNum;
}

void Solution_413::test() {
	// write your test here

	// input;
	int n;
	cin >> n;

	// algorithm;
	cout << reverseInteger(n);
}
