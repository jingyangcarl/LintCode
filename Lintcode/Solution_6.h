#pragma once
#include <vector>
#include <algorithm>
using namespace std;

class Solution_6 {
public:
	/**
	* @param A: sorted integer array A
	* @param B: sorted integer array B
	* @return: A new sorted integer array
	*/
	vector<int> mergeSortedArray(vector<int> &A, vector<int> &B);
	vector<int> mergeSortedArray_2(vector<int> &A, vector<int> &B);
};