#include "Solution_433.h"

int Solution_433::numIslands(vector<vector<bool>>& grid) {
	// write your code here
	return 0;
}

void Solution_433::test() {
	// write your test here

	// input
	int row, col;
	cin >> row >> col;
	vector<vector<bool>> grid(row, vector<bool>(col, false));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			bool current;
			cin >> current;
			grid[i][j] = current;
		}
	}

	// algorithm and output
	cout << numIslands(grid);
}
