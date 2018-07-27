#include "Solution_15.h"

vector<vector<int>> Solution_15::permute(vector<int>& nums) {
	// write your code here
	vector<vector<int>> result;
	vector<int> permutation;
	vector<int> tags(nums.size(), 1);
	permute(result, nums, tags, permutation);
	return result;
}

void Solution_15::permute(vector<vector<int>>& result, vector<int>& nums, vector<int> &tags, vector<int> &permutation) {

	if (permutation.size() == nums.size()) result.push_back(permutation);
	else {
		for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++) {
			if (tags.at(iter - nums.begin()) == 1) {
				permutation.push_back(*iter);
				tags[iter - nums.begin()] = 0;
				permute(result, nums, tags, permutation);
				tags[iter - nums.begin()] = 1;
				permutation.pop_back();
			}
		}
	}
}