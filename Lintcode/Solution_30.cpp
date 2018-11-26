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