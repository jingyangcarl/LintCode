#pragma once
#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution_56 {
public:
	/**
	 * @param numbers: An array of Integer
	 * @param target: target = numbers[index1] + numbers[index2]
	 * @return: [index1, index2] (index1 < index2)
	 */
	vector<int> twoSum(vector<int> &numbers, int target);
	vector<int> twoSum_2(vector<int> &numbers, int target);
	void test();
};