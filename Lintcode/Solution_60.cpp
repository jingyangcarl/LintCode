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
	// binary

	return 0;
}

void Solution_60::test() {
	// write your test here
}