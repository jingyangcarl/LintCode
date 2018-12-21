#include "Solution_111.h"

int Solution_111::climbStairs(int n) {
	// write your code here
	int accumulation(0), ways(0);
	climbStairs(n, accumulation, ways);
	return ways;
}

int Solution_111::climbStairs_2(int n) {
	// write your code here
	// Carl:
	// Idea: Fibonacci sequence
	// which is basically dynamic programming
	vector<int> dp(n+1, 1);
	for (int i = 2; i < n + 1; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	dp[0] = 0;
	return dp[n];
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
	cout << climbStairs_2(n);
}
