#include "Solution_100.h"

int Solution_100::removeDuplicates(vector<int>& nums) {
	// write your code here

	int newNum(-1);
	vector<int>::iterator iter;
	for (iter = nums.begin(); iter != nums.end(); iter++) {
		if (*iter != newNum) newNum = *iter;
		else nums.erase(iter--);
	}

	return nums.size();
}

void Solution_100::test() {

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
