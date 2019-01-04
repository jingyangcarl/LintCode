#pragma once
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution_138 {
public:
	/**
	 * @param nums: A list of integers
	 * @return: A list of integers includes the index of the first number and the index of the last number
	 */
	vector<int> subarraySum(vector<int> &nums);
	vector<int> subarraySum_2(vector<int> &nums);
	void test();
};