#include "Solution_156.h"

vector<Interval> Solution_156::merge(vector<Interval>& intervals) {
	// write your code here

	stack<int> intervalStack;
	vector<int> intervalVector;
	vector<Interval>::iterator iter = intervals.begin();
	if (iter != intervals.end()) {
		intervalStack.push((*iter).start);
		intervalStack.push((*iter).end);
	}
	else {
		return intervals;
	}

	for (iter; iter != intervals.end(); iter++) {
		int curStart = (*iter).start;
		int curEnd = (*iter).end;

		if (curStart > intervalStack.top()) {
			// top < curStart < curEnd
			intervalStack.push(curStart);
			intervalStack.push(curEnd);
		}
		else if (curStart == intervalStack.top()) {
			// top = curStart < curEnd
			intervalStack.pop();
			intervalStack.push(curEnd);
		}
		else if (curEnd > intervalStack.top()) {
			// curStart < top < curEnd
			intervalStack.pop();
			intervalStack.push(curEnd);
		}
		else if (curEnd == intervalStack.top()) {
			// curStart < top = curEnd
			// do nothing
		}
		else if (curEnd < intervalStack.top()) {
			// curStart < curEnd < top
			// do nothing
		}
		else {
			return intervals;
		}
	}


}
