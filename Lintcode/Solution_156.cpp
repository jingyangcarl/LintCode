#include "Solution_156.h"

vector<Interval> Solution_156::merge(vector<Interval>& intervals) {
	// write your code here

	// sort first
	sort(intervals.begin(), intervals.end(), cmp);

	vector<int> intervalVector;
	vector<Interval>::iterator iter = intervals.begin();
	if (iter != intervals.end()) {
		intervalVector.push_back((*iter).start);
		intervalVector.push_back((*iter).end);
		iter++;
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
		else if (curEnd <= intervalVector.back()) {
			// curStart < top = curEnd
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

bool Solution_156::cmp(const Interval & x, const Interval & y) {
	return x.start < y.start;
}

void Solution_156::test() {
	// write your test here

	// intput
	int n;
	cin >> n;
	vector<Interval> input;
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		Interval element(start, end);
		input.push_back(element);
	}

	// algorithm
	vector<Interval> output;
	output = merge(input);

	// output;
	for (int i = 0; i < output.size(); i++) {
		cout << output.at(i).start << ' ' << output.at(i).end << ' ';
	}
}
