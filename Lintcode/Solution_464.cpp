#include "Solution_464.h"

void Solution_464::sortIntegers2(vector<int>& A) {
	// write your code here

	// quick sort
}

void Solution_464::sortIntegers2_2(vector<int>& A) {
	// write your code here

	// merge sort
}

void Solution_464::sortIntegers2_3(vector<int>& A) {
	// write your code here

	// heap sort
}

void Solution_464::test() {
	// write your test here

	// input
	vector<int> A;
	int n;
	cin >> n;
	for (int i = 0; i < A.size(); i++) {
		int num;
		cin >> num;
		A.push_back(num);
	}

	// algorithm
	sortIntegers2(A);

	// output;
	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << ' ';
	}
}
