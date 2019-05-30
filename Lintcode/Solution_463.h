#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Solution_463 {
public:
	/**
	 * @param A: an integer array
	 * @return: nothing
	 */
	void sortIntegers(vector<int>& A);
	void quickSort(vector<int>& A, int begin, int end);
	void test();
};