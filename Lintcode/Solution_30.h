#pragma once
#include <vector>
#include <iostream>
using namespace std;

//Definition of Interval:
class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};


class Solution_30 {
public:
	/**
	* @param intervals: Sorted interval list.
	* @param newInterval: new interval.
	* @return: A new interval list.
	*/
	void test();
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval);
	vector<Interval> insert_2(vector<Interval> &intervals, Interval newInterval);
};