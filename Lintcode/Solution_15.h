#pragma once
#include <vector>
#include <algorithm>
using namespace std;

class Solution_15 {
public:
	/*
	* @param nums: A list of integers.
	* @return: A list of permutations.
	*/
	vector<vector<int>> permute(vector<int> &nums);
	void permute(vector<vector<int>> &result, vector<int> &nums, vector<int> &tags, vector<int> &permutation);
};