#pragma once
#include <vector>
using namespace std;

class Solution_5 {
public:
	/*
	* @param n: An integer
	* @param nums: An array
	* @return: the Kth largest element
	*/
	int kthLargestElement(int n, vector<int> &nums);
	int kthLargestElement_2(int n, vector<int> &nums);
	int kthLargestElement_3(int n, vector<int> &nums);

	int partitionLarge(vector<int> &nums, int left, int right);
	int partitionSmall(vector<int> &nums, int left, int right);

	int runningTest(int n, vector<int> &nums);
};