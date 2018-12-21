#pragma once
#include <iostream>
using namespace std;

class Solution_111 {
public:
	/**
	 * @param n: An integer
	 * @return: An integer
	 */
	int climbStairs(int n);
	int climbStairs(int n, int accumulation, int &ways);
	void test();
};