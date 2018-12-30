#include "Solution_115.h"

int Solution_115::uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	// write your code here

	// Carl: 
	// Idea:
	// do the dynamic programming
	// when the double loop starts, change all the 1 into 0 and do the sum;
	
	// initialization
	// the last element should be 0
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	bool obstacle(false);
	obstacleGrid[m - 1][n - 1] = 1;
	// the last row should all be set to 1
	obstacle = false;
	for (int i = 0; i < n - 1; i++) {
		if (obstacleGrid[m - 1][i] == 1) obstacle = true;
		obstacleGrid[m - 1][i] = obstacle ? 0 : 1;
	}
	// the last col should all be set to 1
	obstacle = false;
	for (int i = 0; i < m - 1; i++) {
		if (obstacleGrid[i][n - 1] == 1) obstacle = true;
		obstacleGrid[m - 1][i] = obstacle ? 0 : 1;
	}

	// count the other elements
	for (int i = m - 2; i >= 0; i--)
		for (int j = n - 2; j >= 0; j--)
			if (obstacleGrid[i][j] == 1) obstacleGrid[i][j] = 0;
			else obstacleGrid[i][j] = obstacleGrid[i][j + 1] + obstacleGrid[i + 1][j];

	// return the value
	return obstacleGrid[0][0];
}

void Solution_115::test() {
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
