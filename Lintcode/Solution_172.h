#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Solution_172 {
public:
	/*
	 * @param A: A list of integers
	 * @param elem: An integer
	 * @return: The new length after remove
	 */
	int removeElement(vector<int> &A, int elem);
	int removeElement_2(vector<int> &A, int elem);
	int removeElement_3(vector<int> &A, int elem);
	void test();
};