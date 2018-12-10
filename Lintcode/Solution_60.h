#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Solution_60 {
public:
	/**
	 * @param A: an integer sorted array
	 * @param target: an integer to be inserted
	 * @return: An integer
	 */
	int searchInsert(vector<int> &A, int target);
	int searchInsert_2(vector<int> &A, int target);
	void test();
};