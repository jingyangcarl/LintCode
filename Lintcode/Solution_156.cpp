#include "Solution_156.h"

vector<Interval> Solution_156::merge(vector<Interval>& intervals) {
	// write your code here

	vector<int> intervalVector;
	vector<Interval>::iterator iter = intervals.begin();
	if (iter != intervals.end()) {
		intervalVector.push_back((*iter).start);
		intervalVector.push_back((*iter).end);
	}
	else {
		return intervals;
	}

	for (iter; iter != intervals.end(); iter++) {
		int curStart = (*iter).start;
		int curEnd = (*iter).end;

		if (curStart > intervalVector.back()) {
			// top < curStart < curEnd
			intervalVector.push_back(curStart);
			intervalVector.push_back(curEnd);
		}
		else if (curStart == intervalVector.back()) {
			// top = curStart < curEnd
			intervalVector.pop_back();
			intervalVector.push_back(curEnd);
		}
		else if (curEnd > intervalVector.back()) {
			// curStart < top < curEnd
			intervalVector.pop_back();
			intervalVector.push_back(curEnd);
		}
		else if (curEnd == intervalVector.back()) {
			// curStart < top = curEnd
			// do nothing
		}
		else if (curEnd < intervalVector.back()) {
			// curStart < curEnd < top
			// do nothing
		}
		else {
			return intervals;
		}
	}

	vector<Interval> result;
	for (int i = 0; i < intervalVector.size(); i+=2) {
		Interval element(intervalVector.at(i), intervalVector.at(i + 1));
		result.push_back(element);
	}

	return result;
}
