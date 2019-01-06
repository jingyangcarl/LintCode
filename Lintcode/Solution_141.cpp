#include "Solution_141.h"

int Solution_141::sqrt(int x) {
	// write your code here
	if (x == 1) return 1;
	else if (x == 0) return 0;
	for (long long i = x / 2; i > 0; i--)
		if (i*i <= x) return i;
}

int Solution_141::sqrt_2(int x) {
	// write your code here
	
	// Carl:
	// Idea: binary search
	long long l(0), r(x / 2), mid;
	while (l <= r) {
		mid = (l + r) / 2;
		long long sqrMid = mid * mid;
		long long sqrMid_ = (mid + 1)*(mid + 1);
		if (sqrMid <= x && sqrMid_ > x) return mid;
		else if (sqrMid_ <= x) l = mid + 1;
		else if (sqrMid > x) r = mid;
	}
}

void Solution_141::test() {
	// write your test here

	// input
	int x;
	cin >> x;

	// algorithm and out
	cout << sqrt_2(x);
}