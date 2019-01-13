#include "Solution_209.h"

char Solution_209::firstUniqChar(string & str) {
	// Write your code here
	unordered_map<char, int> charMap;
	unordered_map<char, int>::iterator iter;
	for (int i = 0; i < str.size(); i++) {
		iter = charMap.find(str[i]);
		if (iter == charMap.end()) charMap.insert(pair<char, int>(str[i], 1));
		else (*iter).second++;
	}
	iter = charMap.begin();
	while (iter != charMap.end()) {
		if ((*iter).second == 1)
			return (*iter).first;
		iter++;
	}
}

char Solution_209::firstUniqChar_2(string & str) {
	// write your code here
	vector<int> charVec(256, 0);
	for (int i = 0; i < str.size(); i++)
		charVec[str[i]]++;
	for (int i = 0; i < charVec.size(); i++)
		if (charVec[i] == 1)
			return (char)i;
}

void Solution_209::test() {
	// write your test here

	// input
	string s;
	cin >> s;

	// algorithm and output
	cout << firstUniqChar(s);
}
