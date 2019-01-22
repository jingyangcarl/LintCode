#include "Solution_464.h"

void Solution_464::sortIntegers2(vector<int>& A) {
	// write your code here

	// quick sort
	sortIntegers2(A, 0, A.size() - 1);
}

void Solution_464::sortIntegers2(vector<int>& A, int left, int right) {
	// write your code here
	int i(left), j(right);
	while (i < j) {
		while (A[i] <= A[0]) i++;
		while (A[j] > A[0]) j--;

		A[i] = A[i] ^ A[j];
		A[j] = A[i] ^ A[j];
		A[i] = A[i] ^ A[j];
	}
	A[0] = A[0] ^ A[i];
	A[i] = A[0] ^ A[i];
	A[0] = A[0] ^ A[i];

	sortIntegers2(A, left, i);
	sortIntegers2(A, i + 1, right);
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
