#include "Solution_445.h"

double Solution_455::cosineSimilarity(vector<int>& A, vector<int>& B) {
	// write your code here

	if (A.empty()) return 2.0;
	double AB(0.0), AA(0.0), BB(0.0);
	for (int i = 0; i < A.size(); i++) {
		AB += A[i] * B[i];
		AA += A[i] * A[i];
		BB += B[i] * B[i];
	}

	return (sqrt(AA)*sqrt(BB)) ? AB / (sqrt(AA)*sqrt(BB)) : 2.0;
}

void Solution_455::test() {
	// write your test here

	// input;
	int n;
	cin >> n;
	vector<int> A, B;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		A.push_back(num);
	}
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		B.push_back(num);
	}

	// algorithm and output
	cout << cosineSimilarity(A, B);
}
