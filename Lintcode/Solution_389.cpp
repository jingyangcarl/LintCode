#include "Solution_389.h"

bool Solution_389::isValidSudoku(vector<vector<char>>& board) {
	// write your code here
	for (int i = 0; i < board.size(); i++) {
		vector<int> check_1(10, 0);
		vector<int> check_2(10, 0);
		vector<int> check_3(10, 0);
		for (int j = 0; j < board[0].size(); j++) {
			// for rows
			if (board[i][j] != '.') {
				if (check_1[board[i][j] - '0'] == 1) return false;
				check_1[board[i][j] - '0']++;
			}

			// for cols
			if (board[j][i] != '.') {
				if (check_2[board[j][i] - '0'] == 1) return false;
				check_2[board[j][i] - '0']++;
			}

			// for nine-neighbors
			// XY represents ij before and after the transformation
			// 00 01 02 03 04 05 06 07 08 -> 00 01 02 10 11 12 20 21 22
			// 10 11 12 13 14 15 16 17 18 -> 03 04 05 13 14 15 23 24 25
			// 20 21 22 23 24 25 26 27 28 -> 06 07 08 16 17 18 26 27 28
			// 30 31 32 33 34 35 36 37 38 -> 30 31 32 40 41 42 50 51 52
			// 40 41 42 43 44 45 46 47 48 -> 33 34 35 43 44 45 53 54 55
			if (board[3 * (i / 3) + (j / 3)][3 * (i % 3) + (j % 3)] != '.') {
				if (check_3[board[3 * (i / 3) + j / 3][3 * (i % 3) + j % 3] - '0'] == 1) return false;
				check_3[board[3 * (i / 3) + j / 3][3 * (i % 3) + j % 3] - '0']++;
			}
		}
	}

	return true;
}

void Solution_389::test() {
	// write your test here

	// intput;
	vector<vector<char>> board(9, vector<char>(9, ','));
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			char entry;
			cin >> entry;
			board[i][j] = entry;
		}
	}

	// algorithm and output
	cout << isValidSudoku(board);
}