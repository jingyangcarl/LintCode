#include "Solution_82.h"

int Solution_82::singleNumber(vector<int>& A) {
	// write your code here

	unordered_map<int, int> aMap;
	vector<int>::iterator iter;
	for (iter = A.begin(); iter != A.end(); iter++) {
		unordered_map<int, int>::iterator locator(aMap.find(*iter));
		if (locator == aMap.end())
			aMap.insert(pair<int, int>(*iter, 1));
		else
			aMap.erase(*iter);
	}
	return (*aMap.begin()).first;
}

void Solution_82::test() {
}
