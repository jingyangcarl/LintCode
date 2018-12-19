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

int Solution_110::minPathSum_2(vector<vector<int>>& grid) {
	// Carl:
	// Idea:
	// the recursion in minPathSum(vector<vector<int>>) will cost a lot of time
	// however, there is redundent recursion, which should be stored to save time
	vector<vector<int>> stored;
	for (vector<vector<int>>::iterator iterI = grid.begin(); iterI != grid.end(); iterI++) {
		vector<int> rows;
		for (vector<int>::iterator iterJ = (*iterI).begin(); iterJ != (*iterI).end(); iterJ++)
			rows.push_back(-1);
		stored.push_back(rows);
	}

	return minPathSum(grid, stored, 0, 0);
}

int Solution_110::minPathSum(vector<vector<int>>& grid, int row, int col) {
	// write your code here

	// Carl:
	// Idea:
	// let's say the matrix is three by three with the follwing elements
	// 1 3 1
	// 1 5 1
	// 4 2 1
	// start from the very first element, which is 1 on the top left corner;
	// there are only two ways that will lead to the bottom right
	// STEP 1
	// left: 1 -> 3
	// down: 1 -> 1
	// if we move on to the left and stop on 3, there will be another two choices
	// STEP 2
	// left: 1 -> 3 -> 1
	// down: 1 -> 3 -> 5
	// if we move on to the left and stop on 1, there will be only one choice, which is going down
	// STEP 3
	// down: 1 -> 3 -> 1 -> 1
	// if we move downward and stop on 1, there will be the last choice, which is going down
	// STEP 4
	// down: 1 -> 3 -> 1 -> 1 -> 1, leads to 7
	// here we walk from the very first element all the way down to the last one
	// let's move back to STEP 2 and take the down track and stop on 5, there will be two choices
	// STEP 3'
	// left: 1 -> 3 -> 5 -> 1
	// down: 1 -> 3 -> 5 -> 2
	// and the following steps on both side will finally lead to the last element
	// STEP 4'
	// left: 1 -> 3 -> 5 -> 2 -> 1, leads to 12
	// down: 1 -> 3 -> 5 -> 1 -> 1, leads to 11
	// when tracking back to the first step and choose to go down, the procedure is the same as above
	// hence, if we consider this question in a back-direction, which is from the last to the first
	// the way we choose the direction to move on only depends on the minimum total value on each possible direction

	if (row == grid.size() - 1 && col == grid.at(0).size() - 1)
		return grid.at(row).at(col);
	else if (row == grid.size() - 1)
		return grid.at(row).at(col) + minPathSum(grid, row, col + 1);
	else if (col == grid.at(0).size() - 1)
		return grid.at(row).at(col) + minPathSum(grid, row + 1, col);
	else
		return grid.at(row).at(col) + min(minPathSum(grid, row, col + 1), minPathSum(grid, row + 1, col));
}

int Solution_110::minPathSum(vector<vector<int>>& grid, vector<vector<int>>& stored, int row, int col) {
	// write your code here

	// Carl: 
	// Idea: 
	// Memory Search

	if (stored.at(row).at(col) != -1)
		return stored.at(row).at(col);
	else {
		if (row == grid.size() - 1 && col == grid.at(0).size() - 1)
			return grid.at(row).at(col);
		else if (row == grid.size() - 1)
			stored.at(row).at(col) = grid.at(row).at(col) + minPathSum(grid, stored, row, col + 1);
		else if (col == grid.at(0).size() - 1)
			stored.at(row).at(col) = grid.at(row).at(col) + minPathSum(grid, stored, row + 1, col);
		else
			stored.at(row).at(col) = grid.at(row).at(col) + min(minPathSum(grid, stored, row, col + 1), minPathSum(grid, stored, row + 1, col));
		return stored.at(row).at(col);
	}
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
	cout << minPathSum_2(grid);
}