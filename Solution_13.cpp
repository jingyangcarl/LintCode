#include "Solution_13.h"

int Solution_13::strStr(const char * source, const char * target) {
	// write your code here
	if (source && target) {
		string strSource(source), strTarget(target);
		for (string::iterator iter = strSource.begin(); iter != strSource.end() - strTarget.size(); iter++) {
			return strSource.find(strTarget.c_str(), iter - strSource.begin(), strTarget.size());
		}

		if (strSource == strTarget) return 0;
	}
	return -1;
}
