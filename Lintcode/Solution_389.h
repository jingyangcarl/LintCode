#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Solution_389 {
public:
	/**
	 * @param board: the board
	 * @return: whether the Sudoku is valid
	 */
	bool isValidSudoku(vector<vector<char>> &board);
	void test();
};