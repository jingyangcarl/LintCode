#include "Solution_44.h"

int Solution_44::minSubArray(vector<int>& nums) {
	// write your code here

	// Carl:
	// Idea:
	// the idea is the same as Solution_41, which is maxSubArray();
	// for details, see Solution_41. Maximum Subarray
	// Pseudocode:
	// do the sum while in the iteration
	// if the sum < 0, continue summing
	// else if save the value and continue the iteration with sum initialization

	int sum(INT_MAX), sumTemp(0);
	vector<int>::iterator iter;

	for (iter = nums.begin(); iter != nums.end(); iter++) {
		sumTemp += *iter;
		sum = sumTemp < sum ? sumTemp : sum;
		sumTemp = sumTemp > 0 ? 0 : sumTemp;
	}

	return sum;
}

void Solution_44::test() {
	// write your test here

	// Carl: input
	int n;
	cin >> n;
	vector<int> nums;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		nums.push_back(num);
	}

	// Carl: algorithm
	n = minSubArray(nums);

	// Carl: output
	cout << n << endl;
}