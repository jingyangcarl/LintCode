#include "Solution_211.h"

bool Solution_211::Permutation(string & A, string & B) {
	// write your code here
	string strVecA(256, 0), strVecB(256, 0);
	if (A.size() == B.size()) {
		for (int i = 0; i < A.size(); i++) {
			strVecA[A[i]]++;
			strVecB[B[i]]++;
		}
	}
	else return false;

	return strVecA == strVecB;
}

void Solution_211::test() {
	// write your test here

	// input
	string A, B;
	cin >> A >> B;

	// algorithm and output
	cout << Permutation(A, B);
}
