#pragma once
#include <vector>
#include <set>
using namespace std;

class Solution_16 {
public:
	/*
	* @param :  A list of integers
	* @return: A list of unique permutations
	*/
	vector<vector<int>> permuteUnique(vector<int> &nums);
	void permuteUnique(set<vector<int>> &result, vector<int> &nums, vector<int> &tags, vector<int> &permutation);
};