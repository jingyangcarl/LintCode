#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Solution_114 {
public:
	/**
	 * @param m: positive integer (1 <= m <= 100)
	 * @param n: positive integer (1 <= n <= 100)
	 * @return: An integer
	 */
	int uniquePaths(int m, int n);
	int uniquePaths_2(int m, int n);
	void uniquePaths(int m, int n, int curM, int curN, int &paths);
	void test();
};