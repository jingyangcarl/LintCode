#include "Solution_397.h"

int Solution_397::longestIncreasingContinuousSubsequence(vector<int>& A) {
	// write your code here

	bool direction(true), currentDir(true);
	if (A.size() <= 1) return A.size();
	int num(A[0]), length(1), maxLen(0);
	// true for increase, false for decrease
	if (A[1]) direction = A[0] < A[1] ? true : false;
	for (int i = 1; i < A.size(); i++) {
		currentDir = A[i] > num ? true : false;
		if (currentDir == direction)
			length++;
		else {
			direction = !direction;
			maxLen = length > maxLen ? length : maxLen;
			length = 1;
		}
		num = A[i];
	}
	return length > maxLen ? length : maxLen;
}

void Solution_397::test() {
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