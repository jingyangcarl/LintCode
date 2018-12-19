#include "Solution_110.h"

int Solution_110::minPathSum(vector<vector<int>>& grid) {
	// write your code here
	// try dynamic programming
	// try divide and conquer
	// try back tracking

	// Carl: 
	// Idea: 
	// do recursion
	return minPathSum(grid, 0, 0);
}

int Solution_110::minPathSum(vector<vector<int>>& grid, int row, int col) {
	// write your code here

	// 

	if (row == grid.size() - 1 && col == grid.at(0).size() - 1)
		return grid.at(row).at(col);
	else if (row == grid.size() - 1)
		return grid.at(row).at(col) + minPathSum(grid, row, col + 1);
	else if (col == grid.at(0).size() - 1)
		return grid.at(row).at(col) + minPathSum(grid, row + 1, col);
	else
		return grid.at(row).at(col) + min(minPathSum(grid, row, col + 1), minPathSum(grid, row + 1, col));
}

void Solution_110::test() {
	// write your code here

	// input
	int row, col;
	cin >> row >> col;
	vector<vector<int>> grid;
	vector<vector<int>>::iterator iterI;
	for (int i = 0; i < row; i++) {
		vector<int> rowNum;
		for (int j = 0; j < col; j++) {
			int num;
			cin >> num;
			rowNum.push_back(num);
		}
		grid.push_back(rowNum);
	}

	// algorithm and output
	cout << minPathSum(grid);
}
