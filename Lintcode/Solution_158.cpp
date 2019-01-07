#include "Solution_158.h"

bool Solution_158::anagram(string & s, string & t) {
	// write your code here

	vector<int> sVec(256, 0), tVec(256, 0);

	for (int i = 0; i < s.length(); i++)
		sVec[s[i]]++;

	for (int i = 0; i < t.length(); i++)
		tVec[t[i]]++;

	for (int i = 0; i < 256; i++)
		if (sVec[i] != tVec[i])
			return false;

	return true;
}

bool Solution_158::anagram_2(string & s, string & t) {
	// write your code here

	// Idea:
	// doing the sum, even if there is a possibility that the strings are different with same ASCII sum (e.g.: "az" and "by")
	// the way of decreasing the possibility is doing the sqare

	int sSum(0), tSum(0);

	if (s.length() == t.length()) {
		for (int i = 0; i < s.length(); i++) {
			sSum += s[i] * s[i];
			tSum += t[i] * t[i];
		}
		return sSum == tSum ? true : false;
	}
	else return false;
}

void Solution_158::test() {
	// write your test here

	// input;
	string s, t;
	cin >> s >> t;

	// algorithm and output
	cout << anagram(s, t);
}
