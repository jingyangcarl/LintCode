#include "Solution_53.h"

string Solution_53::reverseWords(string & s) {
	// write your code here

	// Carl:
	// Idea:
	// record the start of the word and the start of the spaces
	// the characters in between are a word

	string::iterator iter, iterWord(s.end());
	bool saveTag(0);
	stack<string> strStack;

	for (iter = s.begin(); iter != s.end(); iter++) {
		if (saveTag == 0 && *iter != ' ') {
			iterWord = iter;
			saveTag = 1;
		}
		else if (saveTag == 1 && *iter == ' ') {
			string word = s.substr(iterWord - s.begin(), iter - iterWord);
			if (word.size()) strStack.push(word);
			saveTag = 0;
		}
	}
	if (saveTag == 1 && iterWord != s.end()) {
		// boundary detection 
		string word = s.substr(iterWord - s.begin(), iter - iterWord);
		if (word.size()) strStack.push(word);
	}

	string result;
	while (!strStack.empty()) {
		result += strStack.top() + " ";
		strStack.pop();
	}

	return result;
}

void Solution_53::test() {
	// write your test here

	// Carl: input
	string s, r;
	getline(cin, s);

	// Carl: algorithm
	r = reverseWords(s);

	// Carl: output
	cout << r << endl;
}