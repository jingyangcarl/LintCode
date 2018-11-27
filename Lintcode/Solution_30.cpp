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

	// (a,b),(c,d) inserted with (i,j)
	//							|	SS	|	SE	|	ES	|	EE	|
	// i < a < d <= j			|	0	|	0	|	2	|	2	|	(a,b),(c,d)	->	(i,j)
	// i < a < c <= j < d		|	0	|	0	|	2	|	1	|	(a,b),(c,d) ->	(i,d)
	// i < a < b <= j < c		|	0	|	0	|	1	|	1	|	(a,b),(c,d) ->	(i,j),(c,d)
	// i < a <= j < b			|	0	|	0	|	1	|	0	|	(a,b),(c,d) ->	(i,b),(c,d)
	// i < j < a				|	0	|	0	|	0	|	0	|	(a,b),(c,d) ->	(i,j),(a,b),(c,d)
	// a <= i < b < d <= j		|	1	|	0	|	2	|	2	|	(a,b),(c,d) ->	(a,j)
	// a <= i < b < c <= j < d	|	1	|	0	|	2	|	1	|	(a,b),(c,d) ->	(a,d)
	// a <= i < b <= j < c		|	1	|	0	|	1	|	1	|	(a,b),(c,d) ->	(a,j),(c,d)
	// a <= i < j < b			|	1	|	0	|	1	|	0	|	(a,b),(c,d) ->	(a,b),(c,d)
	// b <= i < c < d <=j		|	1	|	1	|	2	|	2	|	(a,b),(c,d) ->	(a,b),(i,j)
	// b <= i < c <= j < d		|	1	|	1	|	2	|	1	|	(a,b),(c,d) ->	(a,b),(i,d)
	// b <= i < j < c			|	1	|	1	|	1	|	1	|	(a,b),(c,d) ->	(a,b),(i,j),(c,d)
	// c <= i < d <= j			|	2	|	1	|	2	|	2	|	(a,b),(c,d) ->	(a,b),(c,j)
	// c <= i < j < d			|	2	|	1	|	2	|	1	|	(a,b),(c,d) ->	(a,b),(c,d)
	// d <= i < j				|	2	|	2	|	2	|	2	|	(a,b),(c,d) ->	(a,b),(c,d),(i,j)



}

vector<Interval> Solution_30::insert_2(vector<Interval>& intervals, Interval newInterval) {
	// Carl: the number of all elements in the intervals should be an even number, after inserting the newInterval, this property should not be changed
	// Carl: the idea is to decide whether the index of each element in the newInterval belongs to the following situation
	// Carl: Let's say the inserting index of start and end component in newInterval is indexStart, and indexEnd, we will have
	// if insert (i, j) into (a, b), insert i and j one be one into the list
	// if a < b < i < j -> (a, b, i, j)	-> (a, b), (i, j)
	// if a < b = i < j -> (a, i, j)	-> (a, j)
	// if a < i < b < j -> (a, i, b, j)	-> (a, j)
	// if a = i < b < j -> (i, b, j)	-> (i, j)
	// if i < a < b < j -> (i, a, b, j)	-> (i, j)
	// if a < i < j = b -> (a, i, j)	-> (a, j)
	// if a = i < j = b -> (i, j)		-> (i, j)
	// if i < a < j = b -> (i, a, j)	-> (i, j)
	// if a < i < j < b -> (a, i, j, b)	-> (a, b)
	// if a = i < j < b -> (i, j, b)	-> (i, b)
	// if i < a < j < b -> (i, a, j, b) -> (i, b)
	// if i < j = a < b -> (i, j, b)	-> (i, b)
	// if i < j < a < b -> (i, j, a, b) -> (i, j), (a, b)

	vector<int> linearIntervals;
	vector<Interval>::iterator iterIntervals = intervals.begin();
	// Carl: intervals linearization
	for (iterIntervals = intervals.begin(); iterIntervals != intervals.end(); iterIntervals++) {
		linearIntervals.push_back((*iterIntervals).start);
		linearIntervals.push_back((*iterIntervals).end);
	}

	// Carl: insert start and end
	int startIndex(0), endIndex(0);
	bool startTag(0), endTag(0);
	// Carl: insert start into the linearIntervals
	vector<int>::iterator iterLinear = linearIntervals.begin();
	while (newInterval.start > (*iterLinear)) iterLinear++;
	if (newInterval.start == (*iterLinear)) {
		startTag = 1;
		startIndex = iterLinear - linearIntervals.begin();
	}
	else if (newInterval.start < (*iterLinear)) {
		iterLinear = linearIntervals.insert(iterLinear, newInterval.start);
		startIndex = iterLinear - linearIntervals.begin();
	}
	else {
		// Carl: error
		return vector<Interval>();
	}

	// Carl: insert end into the linearIntervals
	while (newInterval.end > (*iterLinear)) iterLinear++;
	if (newInterval.end == (*iterLinear)) {
		endTag = 1;
		endIndex = iterLinear - linearIntervals.begin();
	}
	else if (newInterval.end < (*iterLinear)) {
		iterLinear = linearIntervals.insert(iterLinear, newInterval.end);
		endIndex = iterLinear - linearIntervals.begin();
	}

	if (linearIntervals.size() % 2 == 1) {
		// Carl: the inserted start or end must be equal to one of the boundaries in the original list
		// Carl: tags for start and end are identified from the insertion above
		if (startTag) {
			// Carl: the start is the same as one of the boundaries including upper boundaried and lower boundaries
			// Carl: if the index of startIndex is an odd, the repeated boundary is an upper boundary
			// Carl: if the index of startIndex is an even, the repeated bounday is a lower boundary

			iterLinear = linearIntervals.begin() + startIndex;
			if (startIndex % 2 == 1) {
				// Carl: odd, indicating the start value is the same as one of an upper boundary
				// Carl: under such situation, the element after the start (start element is included) should be erased
				for (int i = 0; i < endIndex - startIndex; i++)
					iterLinear = linearIntervals.erase(iterLinear);
			}
			else {
				// Carl: even, indicating the start value is the same as one of a lower boundary
				// Carl: under such situation, the element after the start (start element is not included) should be erased
				for (int i = 0; i < endIndex - startIndex; i++)
					iterLinear = linearIntervals.erase(iterLinear+1);
			}
		}
		else if (endTag) {
			// Carl: the end is the same as one of the boundaries including upper boundaries and lower boundaries
			// Carl: if the index of endIndex is an odd, the repeated boundary is a lower boundary
			// Carl: if the index of endIndex is an even, the repreated boundary is an upper boundary

			iterLinear = linearIntervals.begin() + endIndex;
			if (endIndex % 2 == 1) {
				// Carl: odd, indicating the end value is the same as a lower boundary
				for (int i = 0; i < endIndex - startIndex; i++)
					iterLinear = linearIntervals.erase(iterLinear) - 1;
			}
			else {
				// Carl: even, indicating the end value is the same as an upper boundary
				for (int i = 0; i < endIndex - startIndex; i++)
					iterLinear = linearIntervals.erase(iterLinear - 1) - 1;
			}
		}
		else {
			// Carl: error
			return vector<Interval>();
		}
	}
	else {
		// Carl: the inserted start and end are not the same as the previous list at all, or completely the same
	}


	return vector<Interval>();
}
