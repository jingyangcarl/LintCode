#include "Solution_397.h"

int Solution_397::longestIncreasingContinuousSubsequence(vector<int>& A) {
	// write your code here

	bool lastDir, currentDir;
	if (A.size() <= 1) return A.size();
	int length(1), maxLen(1);
	// true for increase, false for decrease
	for (int i = 0; i < A.size() - 1; i++) {
		currentDir = A[i] < A[i + 1] ? true : false;
		if (i != 0) {
			length++;
			maxLen = length > maxLen ? length : maxLen;
			if (lastDir != currentDir) {
				lastDir = !lastDir;
				length = 1;
			}
		}
		else lastDir = currentDir;
	}

	return maxLen = length + 1 > maxLen ? length + 1 : maxLen;
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