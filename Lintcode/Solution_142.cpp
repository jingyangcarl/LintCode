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

bool Solution_142::checkPowerOf2_2(int n) {
	// write your code here

	// Idea:
	// checkPowerOf2(int n) cannot achieve O(1) 
	// there is a phenominon that if a number is the power of 2
	// then the result of bit AND procedure on each digit will be zero
	// for example 0100 == 4, 0011 == 3
	// the 0100 & 0011 = 0;

	if (n <= 0) return false;
	return (n & (n - 1)) == 0 ? true : false;
}

void Solution_142::test() {
	// write your test here

	// input;
	int n;
	cin >> n;

	// algorithm and output
	cout << checkPowerOf2_2(n);
}
