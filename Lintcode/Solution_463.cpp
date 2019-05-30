#include "Solution_463.h"

void Solution_463::sortIntegers(vector<int>& A) {
	// write your code here
	// quick sort
	quickSort(A, 0, A.size());
}

void Solution_463::quickSort(vector<int>& A, int begin, int end) {

	int i = begin, j = end - 1;
	if (i >= j) return;
	while (i < j) {
		while (A[i] <= A[begin] && i < j) i++;
		while (A[j] > A[begin] && i < j) j--;
		int temp = A[i];
		A[i] = A[j];
		A[j] = temp;
	}
	int temp = A[begin];
	A[begin] = A[i];
	A[i] = temp;

	quickSort(A, begin, i - 1);
	quickSort(A, i + 1, end);
}

void Solution_463::test() {
	// input;
	int n;
	cin >> n;
	vector<int> nums;
	
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		nums.push_back(num);
	}

	// algorithm
	sortIntegers(nums);

	// output
	for (int i = 0; i < n; i++) {
		cout << nums[i] << ' ';
	}
}
