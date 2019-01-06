#include "Solution_141.h"

int Solution_141::sqrt(int x) {
	// write your code here
	if (x == 1) return 1;
	else if (x == 0) return 0;
	for (long long i = x / 2; i > 0; i--)
		if (i*i <= x) return i;
}

int Solution_141::sqrt_2(int x) {
	return 0;
}

void Solution_141::test() {
	// write your test here

	// input
	int x;
	cin >> x;

	// algorithm and out
	cout << sqrt(x);
}