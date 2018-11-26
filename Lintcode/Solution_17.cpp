#include "Solution_17.h"

vector<vector<int>> Solution_17::subsets(vector<int>& nums) {
	// write your code here
	sort(nums.begin(), nums.end());
	vector<vector<int>> subsets;
	subsets.push_back(vector<int>());

	for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++) {

		int currentSize = subsets.size();
		vector<vector<int>>::iterator iterSet = subsets.begin();

		for (int i = 0; i < currentSize; i++) {
			vector<int> currentSet = *(subsets.begin() + i);
			currentSet.push_back(*iter);
			subsets.push_back(currentSet);
		}
	}

	return subsets;
}
