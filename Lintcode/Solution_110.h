#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution_110 {
public:
	/**
	 * @param grid: a list of lists of integers
	 * @return: An integer, minimizes the sum of all numbers along its path
	 */
	int minPathSum(vector<vector<int>> &grid);
	int minPathSum_2(vector<vector<int>> &grid);
	int minPathSum_3(vector<vector<int>> &grid);
	int minPathSum(vector<vector<int>> &grid, int row, int col);
	int minPathSum(vector<vector<int>> &grid, vector<vector<int>> &stored, int row, int col);
	void test();
};