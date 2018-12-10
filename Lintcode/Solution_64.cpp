#include "Solution_64.h"

void Solution_64::mergeSortedArray(int A[], int m, int B[], int n) {
	// write your code here

	// Carl: 
	// Idea: 
	// pointer implementation on both array
	int A

}

void Solution_64::mergeSortedArray_2(int A[], int m, int B[], int n) {
	// write your code here

	// Carl: 
	// Idea: 
	// concatenate array B to the end of array A and do quick sort


}

void Solution_64::test() {
	// write your test here

	// Carl: input 
	int m, n, *A, *B;
	cin >> n;
	B = new int[n];
	for (int i = 0; i < n; i++)
		cin >> B[i];
	cin >> m;
	A = new int[m+n];
	for (int i = 0; i < m; i++)
		cin >> A[i];

	// Carl: algorithm
	mergeSortedArray(A, m, B, n);

	// Carl: output
	for (int i = 0; i < m + n; i++)
		cout << A[i] << " ";
}
