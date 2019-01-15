#include "Solution_365.h"

int Solution_365::countOnes(int num) {
	// write your code here
	bitset<32> bitNum(num);
	return bitNum.count();
}

void Solution_365::test() {
	// write your test here

	// input
	int num;
	cin >> num;

	// algorithm and output
	cout << countOnes(num);
}
