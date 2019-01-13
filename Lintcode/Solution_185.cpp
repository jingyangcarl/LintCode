#include "Solution_185.h"

vector<int> Solution_185::printZMatrix(vector<vector<int>>& matrix) {
	// write your code here

	// suppose a matrix is consist of 3 by 4
	// 1 2 3 4;
	// 5 6 7 8;
	// 9 10 11 12;
	// the order should be 
	// A[0][0] -> A[0][1] -> A[1][0] -> A[2][0] -> A[1][1] -> A[0][2] -> A[0][3] -> A[1][2] -> A[2][1] -> A[2][2] -> A[1][3] -> A[2][3]
	// direction: 0 -> 1 -> 1 -> 0 -> 0 -> 0 -> 1 -> 1 -> 1 -> 1
	// there should be a A[3][0] after A[2][1], however, index outranges
	// try recursion

	vector<int> print;
	bool direction(false);
	for (int i = 0; i < matrix.size() + matrix[0].size() - 1; i++) {
		int j = i;
		while (j >= 0) {
			if(!direction && j < matrix.size() && (i-j) < matrix[0].size())
				print.push_back(matrix[i-j][j]);
			if (direction && (i - j) < matrix.size() && j < matrix[0].size())
				print.push_back(matrix[j][i - j]);
			j--;
		}
		direction = !direction;
	}
	return print;
}

void Solution_185::test() {
	// write your test here

	// input
	int r, c;
	cin >> r >> c;
	vector<vector<int>> matrix(r, vector<int>(c, 0));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> matrix[i][j];
		}
	}

	// algorithm
	vector<int> print = printZMatrix(matrix);

	// output
	for (int i = 0; i < print.size(); i++)
		cout << print[i] << ' ';
}
