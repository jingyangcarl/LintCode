#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Solution_433 {
public:
	/**
	 * @param grid: a boolean 2D matrix
	 * @return: an integer
	 */
	int numIslands(vector<vector<bool>> &grid);
	void numIslands(int i, int j, vector<vector<bool>> &grid, vector<vector<bool>> &visited);
	void test();
};