#pragma once
#include <vector>
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
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval);
};