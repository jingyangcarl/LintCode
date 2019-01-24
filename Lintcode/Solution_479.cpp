#include "Solution_479.h"

int Solution_479::secondMax(vector<int>& nums) {
	// write your code here

	int max_1(INT_MIN), max_2(INT_MIN);
	for (int i = 0; i < nums.size(); i++) {
		max_2 = nums[i] > max_1 ? max_1 : (nums[i] > max_2 ? nums[i] : max_2);
		max_1 = nums[i] > max_1 ? nums[i] : max_1;
	}
	return max_2;
}

void Solution_479::test() {
	// write your test here

	// input
	int n;
	cin >> n;
	vector<int> nums;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		nums.push_back(num);
	}

	// algorithm and output;
	cout << secondMax(nums);
}
