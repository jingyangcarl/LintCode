#include "Solution_373.h"

void Solution_373::partitionArray(vector<int>& nums) {
	// write your code here

	// using two index pointer, one for iteration, another for swap from the back

	int front(0), back(nums.size() - 1);
	while (front < back) {
		if (nums[front] % 2 == 0) {
			while (nums[back] % 2 != 1) back--;
			int temp(nums[front]);
			nums[front] = nums[back];
			nums[back] = temp;
			back--;
		}
		front++;
	}
}

void Solution_373::test() {
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
	partitionArray(nums);

	// output
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << ' ';
}