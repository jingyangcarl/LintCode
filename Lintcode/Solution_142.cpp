#include "Solution_142.h"

bool Solution_142::checkPowerOf2(int n) {
	// write your code here

	while (n > 1) {
		if (n % 2 == 1) return false;
		n /= 2;
	}
	if (n == 1) return true;
	else return false;
}

void Solution_142::test() {
	// write your test here

	// input;
	int n;
	cin >> n;

	// algorithm and output
	cout << checkPowerOf2(n);
}
