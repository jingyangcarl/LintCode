#include "Solution_115.h"

int Solution::uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	// write your code here



	return 0;
}

void Solution::test() {
	// write your test here

	// input;
	int m, n;
	cin >> m >> n;
	vector<vector<int>> obstacleGrid(m, vector<int>(n, 0));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> obstacleGrid[i][j];

	// algorithm and output
	cout << uniquePathsWithObstacles(obstacleGrid);
}
