#include "Solution_433.h"

int Solution_433::numIslands(vector<vector<bool>>& grid) {
	// write your code here

	if (grid.empty()) return 0;
	int islands(0);
	vector<vector<bool>> isVisited(grid.size(), vector<bool>(grid[0].size(), 0));
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[0].size(); j++) {
			if (!isVisited[i][j] && grid[i][j]) {
				islands++;
				numIslands(i, j, grid, isVisited);
			}
		}
	}

	return islands;
}

int Solution_433::numIslands_debug(vector<vector<bool>>& grid) {
	// the code here is for debug

	if (grid.empty()) return 0;
	int islands(0);
	vector<vector<bool>> isVisited(grid.size(), vector<bool>(grid[0].size(), 0));
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[0].size(); j++) {
			if (!isVisited[i][j] && grid[i][j]) {
				islands++;
				numIslands(i, j, grid, isVisited);

				cout << "island position: (" << i << ' ' << j << ")" << endl;
				for (int k = 0; k < grid.size(); k++) {
					for (int j_grid = 0; j_grid < grid[0].size(); j_grid++) {
						if (i == k && j == j_grid) cout << '*';
						else if (j == j_grid) cout << ' ';
						cout << grid[k][j_grid] << ' ';
					}
					cout << " | ";
					for (int j_visited = 0; j_visited < grid[0].size(); j_visited++) {
						if (i == k && j == j_visited) cout << '*';
						else if (j == j_visited) cout << ' ';
						cout << isVisited[k][j_visited] << ' ';
					}
					cout << endl;
				}
				cout << endl;
			}
		}
	}

	return islands;
}

void Solution_433::numIslands(int i, int j, vector<vector<bool>>& grid, vector<vector<bool>>& isVisited) {
	// write your code here
	if (grid[i][j] && !isVisited[i][j]) {
		isVisited[i][j] = true;
		if (i - 1 >= 0) numIslands(i - 1, j, grid, isVisited);
		if (i + 1 < grid.size()) numIslands(i + 1, j, grid, isVisited);
		if (j - 1 >= 0) numIslands(i, j - 1, grid, isVisited);
		if (j + 1 < grid[0].size()) numIslands(i, j + 1, grid, isVisited);
	}
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
