#include "Solution_172.h"

int Solution_172::removeElement(vector<int>& A, int elem) {
	// write your code here
	vector<int> B;

	for (int i = 0; i < A.size(); i++) {
		if (A[i] != elem) B.push_back(A[i]);
	}

	A = B;

	return A.size();
}

int Solution_172::removeElement_2(vector<int>& A, int elem) {
	// write your code here

	// CARL:
	// IDEA:
	// do iteration from the first element until the last, if the repeated number occured, swap it with the last numbers

	for (int i = 0; i < A.size(); i++) {
		while (A[A.size() - 1] == elem)
			A.pop_back();
		if (i < A.size() && A[i] == elem) {
			// swap
			A[i] = A[A.size() - 1];
			A.pop_back();
		}
	}

	return A.size();
}

int Solution_172::removeElement_3(vector<int>& A, int elem) {
	// write your code here
	// IDEA:
	// double pointers namely i as well as j
	// i is used for iteration
	// j is used for recording values != elem

	int j(0);
	for (int i = 0; i < A.size(); i++) {
		if (A[i] != elem) {
			A[j++] = A[i];
		}
	}

	return j;
}

void Solution_172::test() {
	// write your test here

	// input
	int n;
	cin >> n;
	vector<int> A;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		A.push_back(num);
	}

	int elem;
	cin >> elem;

	// algorithm and output
	cout << removeElement_2(A, elem) << endl;
	for (int i = 0; i < A.size(); i++)
		cout << A[i] << ' ';
}