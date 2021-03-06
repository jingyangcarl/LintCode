#include "Solution_64.h"

void Solution_64::mergeSortedArray(int A[], int m, int B[], int n) {
	// write your code here

	// Carl:
	// Idea:
	// pointer implementation on both array
	// the method is with 3 layer loop, which is hard to implement and debug
	// not recommended

	int lastPos(0), i, j, k;

	for (i = 0; i < n; i++) {
		// loop in B
		for (j = lastPos; j < m + i; j++) {
			// loop in A
			if (B[i] < A[j]) {
				// move all elements back with offset 1 include and after A[j]
				for (k = 0; k < m + i - j; k++) {
					// the end of elements that needed to be moved in A is
					// current position in A plus elements in A that should be moved plus how many elements in B has been added
					// corrent position in A is j
					// elements in A that should be moved is m-j
					// elements in B has been added is i
					// so it is i + j + m - j = m + i
					A[m + i - k] = A[m + i - k - 1];
				}

				// move in element from B
				A[j] = B[i];
				// save the current position to reduce redundent loop
				lastPos = j;
				break;
			}
		}
		if (j >= m + i) {
			// current value in B is larger than all elements in A
			A[m + i] = B[i];
		}
	}
}

void Solution_64::mergeSortedArray_2(int A[], int m, int B[], int n) {
	// write your code here

	// Carl:
	// Idea:
	// concatenate array B to the end of array A and do quick sort

	for (int i = 0; i < n; i++)
		A[m + i] = B[i];
	sort(A, A + m + n);
}

void Solution_64::mergeSortedArray_3(int A[], int m, int B[], int n) {
	// write your code here

	// Carl:
	// Idea:
	// cause the size of A is the same as m + n,
	// which there are extra spaces to fill the elements
	// hence, using two pointers to compare each elements in A and B in order
	// and fill the largest in the end of A
	// PS: like compare the linked list

	int *pA(A + m - 1), *pB(B + n - 1), *pC(A + m + n - 1);

	while (pA != A - 1 && pB != B - 1)
		*(pC--) = *pA > *pB ? *(pA--) : *(pB--);
	if (pA == A - 1)
		while (pB != B - 1)
			*(pC--) = *(pB--);
	// the followings can be commented out
	if (pB == B - 1)
		while (pA != A - 1)
			*(pC--) = *(pA--);
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
	A = new int[m + n];
	for (int i = 0; i < m; i++)
		cin >> A[i];

	// Carl: algorithm
	mergeSortedArray_3(A, m, B, n);

	// Carl: output
	for (int i = 0; i < m + n; i++)
		cout << A[i] << " ";
}