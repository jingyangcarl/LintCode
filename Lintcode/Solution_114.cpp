#include "Solution_114.h"

int Solution_114::uniquePaths(int m, int n) {
	// write your code here
	int curM(0), curN(0), paths(0);
	uniquePaths(m, n, curM, curN, paths);
	return paths;
}

int Solution_114::uniquePaths_2(int m, int n) {
	// write your code here
	// Carl:
	// Idea:
	// Dynamic Programming
	// let's take a 3 by 3 grid as an example
	// | 6 | 3 | 1 |
	// | 3 | 2 | 1 |
	// | 1 | 1 | 0 |
	// the last element should be 0
	// the last col and last row should all be one
	// and the other elements should be the sum of its right element and bottom element

	vector<vector<int>> dp(m, vector<int>(n, 0));

	// initialization
	// the last element should be 0
	dp[m - 1][n - 1] = 0;
	// the last row should all be set to 1
	for (int i = 0; i < n - 1; i++)
		dp[m - 1][i] = 1;
	// the last col should all be set to 1
	for (int i = 0; i < m - 1; i++)
		dp[i][n - 1] = 1;

	// count the other elements
	for (int i = m - 2; i >= 0; i--)
		for (int j = n - 2; j >= 0; j--)
			dp[i][j] = dp[i][j + 1] + dp[i + 1][j];

	// return the value
	return dp[0][0];
}

void Solution_114::uniquePaths(int m, int n, int curM, int curN, int &paths) {
	if (curM == m - 1 && curN == n - 1) paths++;
	else if (curM <= m - 1 && curN <= n - 1) {
		uniquePaths(m, n, curM + 1, curN, paths);
		uniquePaths(m, n, curM, curN + 1, paths);
	}
	else if (curM > m - 1 || curN > n - 1) return;
}

void Solution_114::test() {
	// write your test here

	// input
	int m, n;
	cin >> m >> n;

	// algorithm and output
	cout << uniquePaths_2(m, n);
}