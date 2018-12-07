#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Solution_41 {
public:
	/**
	 * @param nums: A list of integers
	 * @return: A integer indicate the sum of max subarray
	 */
	int maxSubArray(vector<int> &nums);
	int maxSubArray_2(vector<int> &nums);
	int maxSubArray_3(vector<int> &nums);
	void test();
};