#include "Solution_133.h"

vector<string> Solution_133::longestWords(vector<string>& dictionary) {
	// write your code here

	int maxLen(0);
	vector<string>::iterator iter;
	vector<string> subdic;
	for (iter = dictionary.begin(); iter != dictionary.end(); iter++) {
		if ((*iter).length() > maxLen) {
			maxLen = (*iter).size();
			subdic.clear();
			subdic.push_back(*iter);
		}
		else if ((*iter).length() == maxLen)
			subdic.push_back(*iter);
	}

	return subdic;
}

void Solution_133::test() {
	// write your test here

	// input
	vector<string> dic;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		dic.push_back(s);
	}

	// algorithm
	dic = longestWords(dic);

	// output
	vector<string>::iterator iter;
	for (iter = dic.begin(); iter != dic.end(); iter++)
		cout << *iter << endl;

}
