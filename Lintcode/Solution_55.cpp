#include "Solution_55.h"

bool Solution_55::compareStrings(string & A, string & B) {
	// write your code here

	map<char, int> mapA, mapB;

	string::iterator iter;
	for (iter = A.begin(); iter != A.end(); iter++) {
		if (mapA.find(*iter) == mapA.end())
			mapA.insert(pair<char, int>(*iter, 1));
		else (*mapA.find(*iter)).second++;
	}

	for (iter = B.begin(); iter != B.end(); iter++) {
		map<char, int>::iterator found = mapA.find(*iter);
		if (found == mapA.end())
			return false;
		else if ((*found).second == 1)
			mapA.erase((*found).first);
		else
			(*found).second--;
	}

	return true;
}

void Solution_55::test() {
	// write your test here

	string A, B;

	cin >> A >> B;

	cout << compareStrings(A, B);
}