#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Solution_20 {
public:
	/**
	* @param n an integer
	* @return a list of pair<sum, probability>
	*/
	vector<pair<int, double>> dicesSum(int n);
	void countAvailableSum(int &sum, int &currentSum, int &diceCount, int &availableCount);

	vector<pair<int, double>> dicesSum_2(int n);
};