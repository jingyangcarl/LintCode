#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// Definition of Interval:
class Interval{
public:
	 int start, end;
	 Interval(int start, int end) {
		 this->start = start;
		 this->end = end;
	 }
};

class Solution_156 {
public:
	/**
	 * @param intervals: interval list.
	 * @return: A new interval list.
	 */
	vector<Interval> merge(vector<Interval> &intervals);
	static bool cmp(const Interval& x, const Interval& y);
	void test();
};