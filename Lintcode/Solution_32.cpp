#include "Solution_32.h"

string Solution::minWindow(string & source, string & target) {
	// write your code here

	string::iterator srcIter, tempIter;
	for (srcIter = source.begin(); srcIter != source.end() - target.size(); srcIter++) {

		string temp = target;

		for (tempIter = temp.begin(); tempIter != temp.end(); tempIter++) {
			if (*srcIter == *tempIter) {
				temp.erase(tempIter - target.begin());
				break;
			}
		}


		while (temp.size) {

			for (tgtIter = target.begin(); tgtIter != target.end(); tgtIter++) {

			}
		}

	}
}
