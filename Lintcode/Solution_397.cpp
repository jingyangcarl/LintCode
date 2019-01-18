#include "Solution_397.h"

int Solution::longestIncreasingContinuousSubsequence(vector<int>& A) {
	// write your code here

	bool direction(true), currentDir(true);
	if (A.empty()) return 0;
	int num(A[0]), length(1);
	// true for increase, false for decrease
	for (int i = 1; i < A.size(); i++) {
		currentDir = A[i] > num ? true : false;
		if (currentDir == direction) length++;
		else {
			direction = !direction;
			length = 1;
		}
	}

	return length;
}

void Solution::test() {
	// write your test here

	// input
	vector<int> nums;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		nums.push_back(num);
	}

	// algorithm and output
	cout << longestIncreasingContinuousSubsequence(nums);
}
