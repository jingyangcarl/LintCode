#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Solution_111 {
public:
	/**
	 * @param n: An integer
	 * @return: An integer
	 */
	int climbStairs(int n);
	int climbStairs_2(int n);
	int climbStairs(int n, int accumulation, int &ways);
	void test();
};