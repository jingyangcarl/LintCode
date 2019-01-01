#include "Solution_138.h"

vector<int> Solution_138::subarraySum(vector<int>& nums) {
	// write your code here

	vector<int> pair;
	for (int i = 0; i < nums.size(); i++) {
		int sum(0);
		for (int j = i; j < nums.size(); j++) {
			sum += nums[j];
			if (!sum) {
				pair.push_back(i);
				pair.push_back(j);
			}
		}
	}

	return pair;
}

void Solution_138::test() {
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

	// algorithm
	nums = subarraySum(nums);

	// output;
	cout << nums[0] << ' ' << nums[1] << endl;
}
