#include "Solution_101.h"

int Solution_101::removeDuplicates(vector<int>& nums) {
	// write your code here
	int newNum(-1);
	bool existTwice(false);
	vector<int>::iterator iter;
	for (iter = nums.begin(); iter != nums.end(); iter++) {
		if (newNum != *iter) newNum = *iter, existTwice = false;
		else {
			if (!existTwice) existTwice = true;
			else nums.erase(iter--);
		}
	}
	return nums.size();
}

void Solution_101::test() {
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
	removeDuplicates(nums);

	// output
	vector<int>::iterator iter;
	for (iter = nums.begin(); iter != nums.end(); iter++)
		cout << *iter << " ";
}
