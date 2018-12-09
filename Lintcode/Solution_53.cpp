#include "Solution_53.h"

string Solution_53::reverseWords(string & s) {
	// write your code here

	string::iterator iter, iterWord;
	stack<string> strStack;

	for (iter = s.begin(); iter != s.end(); iter++) {
		if (*iter != ' ') {
			iterWord = iter;
		}
		else {
			string word = s.substr(iterWord - s.begin(), iter - iterWord);
			if (word.size()) strStack.push(word);
		}
	}

	return 0;
}

void Solution_53::test() {
	// write your test here

	// Carl: input
	string s, r;
	cin >> s;

	// Carl: algorithm
	r = reverseWords(s);

	// Carl: output
	cout << r << endl;
}
