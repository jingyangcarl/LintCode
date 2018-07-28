#include "Solution_18.h"

vector<vector<int>> Solution_18::subsetsWithDup(vector<int>& nums) {
	// write your code here
	sort(nums.begin(), nums.end());
	vector<vector<int>> subsets;
	set<vector<int>> subsetEliminate;
	subsets.push_back(vector<int>());
	subsetEliminate.insert(vector<int>());

	for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++) {

		int currentSize = subsets.size();
		vector<vector<int>>::iterator iterSet = subsets.begin();

		for (int i = 0; i < currentSize; i++) {
			vector<int> currentSet = *(subsets.begin() + i);
			currentSet.push_back(*iter);
			subsets.push_back(currentSet);
			subsetEliminate.insert(currentSet);
		}
	}

	subsets.clear();
	for (set<vector<int>>::iterator iter = subsetEliminate.begin(); iter != subsetEliminate.end(); iter++)
		subsets.push_back(*iter);

	return subsets;
}