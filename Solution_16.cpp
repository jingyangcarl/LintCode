#include "Solution_16.h"

vector<vector<int>> Solution_16::permuteUnique(vector<int>& nums) {
	// write your code here
	set<vector<int>> resultSet;
	vector<int> permutation;
	vector<int> tags(nums.size(), 1);
	permuteUnique(resultSet, nums, tags, permutation);

	vector<vector<int>> result;
	for (set<vector<int>>::iterator iter = resultSet.begin(); iter != resultSet.end(); iter++)
		result.push_back(*iter);
	return result;
}

void Solution_16::permuteUnique(set<vector<int>>& result, vector<int>& nums, vector<int>& tags, vector<int>& permutation) {

	if (permutation.size() == nums.size()) result.insert(permutation);
	else {
		for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++) {
			if (tags.at(iter - nums.begin()) == 1) {
				permutation.push_back(*iter);
				tags[iter - nums.begin()] = 0;
				permuteUnique(result, nums, tags, permutation);
				tags[iter - nums.begin()] = 1;
				permutation.pop_back();
			}
		}
	}
}
