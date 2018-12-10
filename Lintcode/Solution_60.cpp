#include "Solution_60.h"

int Solution_60::searchInsert(vector<int>& A, int target) {
	// write your code here

	// Carl:
	// Idea:
	// loop

	vector<int>::iterator iter;
	for (iter = A.begin(); iter != A.end(); iter++) {
		if (*iter >= target)
			break;
	}

	return iter - A.begin();
}

int Solution_60::searchInsert_2(vector<int>& A, int target) {
	// write your code here

	// Carl:
	// Idea:
	// binary search
	// when change the brackets (or begin and end positions), remeber
	// the adjusted end position should be the same as the middle
	// the adjusted begin position should be the middle + 1

	vector<int>::iterator iterBegin(A.begin()), iterEnd(A.end()), iterMid;

	while (iterBegin < iterEnd) {
		iterMid = ((iterBegin - A.begin()) + (iterEnd - A.begin())) / 2 + A.begin();
		if (*iterMid > target)
			//iterEnd = iterMid - 1; REMEMBER: this will cause the pointer outrange
			iterEnd = iterMid;
		else if (*iterMid < target)
			iterBegin = iterMid + 1;
		else
			return iterMid - A.begin();
	}
	return iterEnd - A.begin();
}

void Solution_60::test() {
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
	cin >> n;

	// Carl: algorithm
	n = searchInsert_2(nums, n);

	// Carl: output
	cout << n;
}