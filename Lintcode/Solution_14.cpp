#include "Solution_14.h"

int Solution_14::binarySearch(vector<int>& nums, int target) {
	// write your code here
	int left(0), right(nums.size()-1), mid, index(nums.size());
	while (left < right) {
		mid = (left + right) / 2;
		if (target < nums.at(mid)) right = mid - 1;
		else if (target > nums.at(mid)) left = mid + 1;
		else {
			left = mid / 2;
			right = mid - 1;
			index = mid < index ? mid : index;
		}
	}
	if (index == nums.size()) return -1;
	else return index;
}