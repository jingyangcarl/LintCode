#include <iostream>
#include <vector>
#include "Solution_28.h"
using namespace std;

int main() {

	Solution_28 solution;

	int row, col;
	cin >> row >> col;
	vector<vector<int>> matrix;

	for (int i = 0; i < row; i++) {
		vector<int> rol;
		for (int j = 0; j < col; j++) {
			int num;
			cin >> num;
			rol.push_back(num);
		}
		matrix.push_back(rol);
	}

	int num;
	cin >> num;

	cout << solution.searchMatrix(matrix, num);
	
}