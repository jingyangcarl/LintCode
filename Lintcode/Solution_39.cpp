#include "Solution_39.h"

void Solution_39::recoverRotatedSortedArray(vector<int>& nums) {
	// write your code here

	vector<int>::iterator iter, iterBoundary;
	vector<int> recoverArray;

	// Carl: find the boundary
	for (iter = nums.begin()+1; iter != nums.end(); iter++) {
		if (*iter < *(iter - 1))
			break;
	}

	// Carl: save the elements after the boundary
	iterBoundary = iter;
	while (iter != nums.end()) {
		recoverArray.push_back(*iter);
		iter++;
	}

	// Carl: save the elements before the boundary
	for (iter = nums.begin(); iter != iterBoundary; iter++) {
		recoverArray.push_back(*iter);
	}

	// Carl: copy back
	nums = recoverArray;
	return;
}

void Solution_39::test() {
	// write your test here

	// Carl: input
	int n;
	cin >> n;
	vector<int> rotatedArray;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		rotatedArray.push_back(num);
	}

	// Carl: algorithm
	recoverRotatedSortedArray(rotatedArray);

	// Carl: output
	vector<int>::iterator iter;
	for (iter = rotatedArray.begin(); iter != rotatedArray.end(); iter++) {
		cout << *iter << ' ';
	}
}