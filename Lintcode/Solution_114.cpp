#include "Solution_114.h"

int Solution_114::uniquePaths(int m, int n) {
	// write your code here
	int curM(0), curN(0), paths(0);
	uniquePaths(m, n, curM, curN, paths);
	return paths;
}

void Solution_114::uniquePaths(int m, int n, int curM, int curN, int &paths) {
	if (curM == m && curN == n) paths++;
	else if (curM <= m && curN <= n){
		uniquePaths(m, n, curM + 1, curN, paths);
		uniquePaths(m, n, curM, curN + 1, paths);
	}
	else if (curM > m || curN > n) return;
}

void Solution_114::test() {
	// write your test here

	// input
	int m, n;
	cin >> m >> n;

	// algorithm and output
	cout << uniquePaths(m, n);
}
