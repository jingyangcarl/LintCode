#include "Solution_111.h"

int Solution_111::climbStairs(int n) {
	// write your code here
	int accumulation(0), ways(0);
	climbStairs(n, accumulation, ways);
	return ways;
}

int Solution_111::climbStairs(int n, int accumulation, int &ways) {
	// write your code here
	if (n != 0 && accumulation == n) ways++;
	else if (accumulation < n) {
		climbStairs(n, accumulation + 1, ways);
		climbStairs(n, accumulation + 2, ways);
	}
	else return 0;
}

void Solution_111::test() {
	// write your code here
	// input;
	int n;
	cin >> n;
	cout << climbStairs(n);
}
