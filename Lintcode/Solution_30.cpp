#include "Solution_30.h"

void Solution_30::test() {
	// Carl: run the test

	// Carl: enter the number of Intervals
	int n;
	cout << "Enter the number of Intervals: ";
	cin >> n;

	// Carl: enter intervals
	vector<Interval> intervals;
	cout << "Enter intervals:" << endl;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		Interval interval(a, b);
		intervals.push_back(interval);
	}

	// Carl: enter inserted interval
	cout << "Enter inserted interval: " << endl;
	int a, b;
	cin >> a >> b;
	Interval interval(a, b);

	// Carl: run the algorithm
	intervals = insert(intervals, interval);

	// Carl: show the result
	cout << "After insertion: " << endl;
	vector<Interval>::iterator iter = intervals.begin();
	while (iter != intervals.end()) {
		cout << (*iter).start << " " << (*iter).end << " ";
		iter++;
	}
	cout << endl;

	return;
}

vector<Interval> Solution_30::insert(vector<Interval>& intervals, Interval newInterval) {
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
	vector<int>::iterator iterLinear = linearIntervals.begin();
	if (!linearIntervals.empty()) {
		// Carl: insert start into the linearIntervals
		for (iterLinear; iterLinear != linearIntervals.end(); iterLinear++)
			if (newInterval.start <= (*iterLinear))
				break;
		if (iterLinear != linearIntervals.end()) {
			if (newInterval.start == (*iterLinear)) {
				startTag = 1;
				startIndex = iterLinear - linearIntervals.begin();
			}
			else if (newInterval.start < (*iterLinear)) {
				iterLinear = linearIntervals.insert(iterLinear, newInterval.start);
				startIndex = iterLinear - linearIntervals.begin();
			}

			// Carl: insert end into the linearIntervals
			if (newInterval.end == newInterval.start) {
				iterLinear = linearIntervals.insert(iterLinear + 1, newInterval.end);
				endIndex = iterLinear - linearIntervals.begin();
			}
			else {
				for (iterLinear; iterLinear != linearIntervals.end(); iterLinear++)
					if (newInterval.end <= (*iterLinear))
						break;
				if (iterLinear != linearIntervals.end()) {
					if (newInterval.end == (*iterLinear)) {
						endTag = 1;
						endIndex = iterLinear - linearIntervals.begin();
					}
					else if (newInterval.end < (*iterLinear)) {
						iterLinear = linearIntervals.insert(iterLinear, newInterval.end);
						endIndex = iterLinear - linearIntervals.begin();
					}
				}
				else {
					linearIntervals.push_back(newInterval.end);
					endIndex = linearIntervals.size() - 1;
				}
			}
		}
		else {
			linearIntervals.push_back(newInterval.start);
			linearIntervals.push_back(newInterval.end);
			endIndex = startIndex + 1;
		}
	}
	else {
		linearIntervals.push_back(newInterval.start);
		linearIntervals.push_back(newInterval.end);
		endIndex = startIndex + 1;
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
				if (endIndex % 2 == 1) {
					// Carl: original: (a, b), (c, d)
					// Carl: inserted:    (i,     j)
					for (int i = 0; i < endIndex - startIndex + 1; i++)
						iterLinear = linearIntervals.erase(iterLinear);
				}
				else {
					// Carl: original: (a, b), (c, d)
					// Carl: inserted:    (i,        j)
					for (int i = 0; i < endIndex - startIndex; i++)
						iterLinear = linearIntervals.erase(iterLinear);
				}
			}
			else {
				// Carl: even, indicating the start value is the same as one of a lower boundary
				// Carl: under such situation, the element after the start (start element is not included) should be erased
				if (endIndex % 2 == 1) {
					// Carl: original: (a, b), (c, d)
					// Carl: inserted: (i,        j)
					for (int i = 0; i < endIndex - startIndex; i++)
						iterLinear = linearIntervals.erase(iterLinear + 1);
				}
				else {
					// Carl: original: (a, b), (c, d)
					// Carl: inserted: (i,    j)
					for (int i = 1; i < endIndex - startIndex; i++)
						iterLinear = linearIntervals.erase(iterLinear + 1);
				}
			}
		}
		else if (endTag) {
			// Carl: the end is the same as one of the boundaries including upper boundaries and lower boundaries
			// Carl: if the index of endIndex is an odd, the repeated boundary is a lower boundary
			// Carl: if the index of endIndex is an even, the repreated boundary is an upper boundary

			iterLinear = linearIntervals.begin() + endIndex;
			if (endIndex % 2 == 1) {
				// Carl: odd, indicating the end value is the same as a lower boundary
				if (startIndex % 2 == 1) {
					// Carl: original: (a, b), (c, d)
					// Carl: inserted:   (i,    j)
					for (int i = 0; i < endIndex - startIndex + 1; i++)
						iterLinear = linearIntervals.erase(iterLinear) - 1;
				}
				else {
					// Carl: original: (a, b), (c, d)
					// Carl: inserted:(i,       j)
					for (int i = 0; i < endIndex - startIndex; i++)
						iterLinear = linearIntervals.erase(iterLinear) - 1;
				}
			}
			else {
				// Carl: even, indicating the end value is the same as an upper boundary
				if (startIndex % 2 == 1) {
					// Carl: original: (a, b), (c, d)
					// Carl: inserted:   (i,       j)
					for (int i = 0; i < endIndex - startIndex; i++)
						iterLinear = linearIntervals.erase(iterLinear - 1) - 1;
				}
				else {
					// Carl: original: (a, b), (c, d)
					// Carl: inserted:       (i,   j)
					for (int i = 1; i < endIndex - startIndex; i++)
						iterLinear = linearIntervals.erase(iterLinear - 1) - 1;
				}
			}
		}
		else {
			// Carl: error
			return vector<Interval>();
		}
	}
	else {
		// Carl: the inserted start and end are not the same as the previous list at all, or completely the same
		// Carl: tags for start and end are identified from the insertion above
		if (startTag && endTag) {
			// Carl: both inserted start and end are the same as one the boundaries in the list, including upper boundaries and lower boundaries
			// Carl: if the index of the startIndex is an odd, the repeated starting boundary is an upper boundary
			// Carl: if the index of the startIndex is an even, the repreated starting boundary is a lower boundary

			iterLinear = linearIntervals.begin() + startIndex;
			if (startIndex % 2 == 1) {
				// Carl: odd, the repeated starting boundary is an upper boundary
				if (endIndex % 2 == 1) {
					// Carl: original: (a, b), (c, d)
					// Carl: inserted:	  (i,      j)
					for (int i = 0; i < endIndex - startIndex + 1; i++)
						iterLinear = linearIntervals.erase(iterLinear);
				}
				else {
					// Carl: original: (a, b), (c, d)
					// Carl: inserted:    (i,   j)
					for (int i = 0; i < endIndex - startIndex + 1; i++)
						iterLinear = linearIntervals.erase(iterLinear);
				}
			}
			else {
				// Carl: even, the repreated starting boundary is a lower boundary
				if (endIndex % 2 == 1) {
					// Carl: original: (a, b), (c, d)
					// Carl: inserted: (i,         j)
					for (int i = 1; i < endIndex - startIndex; i++)
						iterLinear = linearIntervals.erase(iterLinear);
				}
				else {
					// Carl: original: (a, b), (c, d)
					// Carl: inserted: (i,      j)
					for (int i = 0; i < endIndex - startIndex; i++)
						iterLinear = linearIntervals.erase(iterLinear);
				}
			}
		}
		else {
			// Carl: no repreat boundaries
			iterLinear = linearIntervals.begin() + startIndex;
			if (startIndex % 2 == 1) {
				if (endIndex % 2 == 1) {
					// Carl: original: (a, b), (c, d)
					// Carl: inserted:   (i,         j)
					for (int i = 0; i < endIndex - startIndex; i++)
						iterLinear = linearIntervals.erase(iterLinear);
				}
				else {
					// Carl: original: (a, b), (c, d)
					// Carl: inserted:   (i,      j)
					for (int i = 0; i < endIndex - startIndex + 1; i++)
						iterLinear = linearIntervals.erase(iterLinear);
				}
			}
			else {
				// Carl: the inserted start is in between each pairs
				if (endIndex % 2 == 1) {
					// Carl: original: (a, b), (c, d)
					// Carl: inserted:       (i,     j)
					iterLinear++;
					for (int i = 1; i < endIndex - startIndex; i++)
						iterLinear = linearIntervals.erase(iterLinear);
				}
				else {
					// Carl: original: (a, b), (c, d)
					// Carl: inserted:       (i,  j)
					iterLinear++;
					for (int i = 0; i < endIndex - startIndex; i++)
						iterLinear = linearIntervals.erase(iterLinear);
				}
			}
		}
	}

	// Carl: de-linearization
	vector<Interval> returnInterval;
	iterLinear = linearIntervals.begin();
	for (int i = 0; i < linearIntervals.size() / 2; i++) {
		returnInterval.push_back(Interval(*iterLinear, *(iterLinear + 1)));
		iterLinear += 2;
	}

	return returnInterval;
}

vector<Interval> Solution_30::insert_2(vector<Interval>& intervals, Interval newInterval) {
	// Carl: try stack
	return vector<Interval>();
}