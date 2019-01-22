#include "Solution_457.h"

int Solution::findPosition(vector<int>& nums, int target) {
	// write your code here
	int left(0), right(nums.size());
	while (left < right) {
		int mid = (left + right) / 2;
		if (nums[mid] == target) return mid;
		else if (nums[mid] < target) left = mid + 1;
		else right = mid;
	}
	return -1;
}

void Solution::test() {
	// write your test here

	// input
	int n;
	cin >> n;
	vector<int> nums;
	for (int i = 0; i < nums.size(); i++) {
		int num;
		cin >> num;
		nums.push_back(num);
	}
	int target;
	cin >> target;

	// algorithm and output
	cout << findPosition(nums, target);

}
