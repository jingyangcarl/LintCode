#include "Solution_6.h"

vector<int> Solution_6::mergeSortedArray(vector<int>& A, vector<int>& B) {
	
	vector<int> C;
	vector<int>::iterator iter;
	
	iter = A.begin();
	while (iter != A.end()) C.push_back(*iter++);

	iter = B.begin();
	while (iter != B.end()) C.push_back(*iter++);

	sort(C.begin(), C.end());

	return C;
}

vector<int> Solution_6::mergeSortedArray_2(vector<int>& A, vector<int>& B) {
	
	vector<int> C;
	vector<int>::iterator iterA = A.begin(), iterB = B.begin();

	while (iterA != A.end() && iterB != B.end())
		C.push_back(*iterA < *iterB ? *iterA++ : *iterB++);

	if (iterA == A.end()) while (iterB != B.end()) C.push_back(*iterB++);
	if (iterB == B.end()) while (iterA != A.end()) C.push_back(*iterA++);

	return C;
}
