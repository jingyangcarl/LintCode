#include "Solution_30.h"

vector<Interval> Solution_30::insert(vector<Interval>& intervals, Interval newInterval) {
	// write your code here

	if (intervals.empty()) {
		intervals.push_back(newInterval);
		return intervals;
	}

	int locatorSS(0), locatorSE(0), locatorES(0), locatorEE(0);
	vector<Interval>::iterator iter;
	iter = intervals.begin();
	while (iter != intervals.end() && newInterval.start > (*iter).start) iter++, locatorSS++;
	iter = intervals.begin();
	while (iter != intervals.end() && newInterval.start > (*iter).end) iter++, locatorSE++;
	iter = intervals.begin();
	while (iter != intervals.end() && newInterval.end > (*iter).start) iter++, locatorES++;
	iter = intervals.begin();
	while (iter != intervals.end() && newInterval.end > (*iter).end) iter++, locatorEE++;

	



}