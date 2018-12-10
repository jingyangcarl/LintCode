#pragma once
#include <iostream>
using namespace std;

class Solution_64 {
public:
	/*
	 * @param A: sorted integer array A which has m elements, but size of A is m+n
	 * @param m: An integer
	 * @param B: sorted integer array B which has n elements
	 * @param n: An integer
	 * @return: nothing
	 */
	void mergeSortedArray(int A[], int m, int B[], int n);
	void mergeSortedArray_2(int A[], int m, int B[], int n);
	void test();
};