#include "Solution_29.h"

bool Solution_29::isInterleave(string & s1, string & s2, string & s3) {
	// write your code here

	string::iterator iter1 = s1.begin(), iter2 = s2.begin(), iter3 = s3.begin();
	int sameLen(0);

	for (iter3 = s3.begin(); iter3 != s3.end(); iter3++) {
		
		if (!s1.empty() && iter1 != s1.end() && iter2 != s2.end() && *iter1 == *iter2 && *iter1 == *iter3) {
			sameLen++;
			*iter1++;
			*iter2++;
		}
		else {
			if (sameLen != 0) {
				if (*iter3 == *iter1) iter2 -= sameLen;
				else if (*iter3 == *iter2) *iter1 -= sameLen;
				else return false;
				sameLen = 0;
			}
			else {
				if (*iter3 == *iter1) iter1++;
				else if (*iter3 == *iter2) iter2++;
				else return false;
			}
		}

	}

	if (iter3 == s3.end())
		return true;
}