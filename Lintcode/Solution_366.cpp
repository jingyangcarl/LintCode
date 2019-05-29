#include "Solution_366.h"

int Solution_366::fibonacci(int n) {
	// write your code here
	int a(0), b(1);

	while (--n) {
		int c = a + b;
		a = b;
		b = c;
	}

	return a;
}

int Solution_366::fibonacci_2(int n) {
	// Carl: recursion formula is OPT(n) = OPT(n-1) + OPT(n-2);
	if (n == 1) return 0;
	if (n == 2) return 1;
	return fibonacci_2(n - 1) + fibonacci_2(n - 2);
}

void Solution_366::test() {
	// input
	int n;
	cin >> n;

	// algorithm and output
	cout << fibonacci_2(n) << endl;
}
