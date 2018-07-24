#include <iostream>
#include <vector>
#include "Solution_6.h"
using namespace std;

int main() {

	int a, b;
	vector<int> A, B, C;

	Solution_6 solution;
	
	A.push_back(1);
	A.push_back(2);
	A.push_back(3);
	A.push_back(4);

	B.push_back(2);
	B.push_back(4);
	B.push_back(5);
	B.push_back(6);

	C = solution.mergeSortedArray(A, B);

	vector<int>::iterator iter = C.begin();
	while (iter != C.end()) cout << *iter++ << " ";


	getchar();
	getchar();
}