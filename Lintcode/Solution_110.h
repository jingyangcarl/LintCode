#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Solution_110 {
public:
	/**
	 * @param grid: a list of lists of integers
	 * @return: An integer, minimizes the sum of all numbers along its path
	 */
	int minPathSum(vector<vector<int>> &grid);
	void test();
};