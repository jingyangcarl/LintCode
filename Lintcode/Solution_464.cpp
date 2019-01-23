#include "Solution_464.h"

void Solution_464::sortIntegers2(vector<int>& A) {
	// write your code here

	// quick sort
	sortIntegers2(A, 0, A.size() - 1);
}

void Solution_464::sortIntegers2(vector<int>& A, int left, int right) {
	// write your code here
	if (left >= right) return;
	else {
		int i(left), j(right);
		int b = i;

		while (i < j) {
			while (i < j && A[j] > A[b]) j--;
			while (i < j && A[i] <= A[b]) i++;
			if (i != j) { A[i] = A[i] ^ A[j]; A[j] = A[j] ^ A[i]; A[i] = A[i] ^ A[j]; }
		}

		if (i != b) { A[b] = A[b] ^ A[i]; A[i] = A[i] ^ A[b]; A[b] = A[b] ^ A[i]; }
		sortIntegers2(A, left, j - 1);
		sortIntegers2(A, j + 1, right);
	}
}

void Solution_464::sortIntegers2_2(vector<int>& A) {
	// write your code here

	// merge sort
	// leave for CSCI 570 - Chapter 5 Divied and Conquer
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
	for (int i = 0; i < n; i++) {
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