#include "Solution_423.h"

bool Solution_423::isValidParentheses(string & s) {
	// write your code here
	stack<char> paraStack;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			paraStack.push(s[i]);
		else {
			if (paraStack.empty()) return false;
			switch (paraStack.top()) {
			case '(':
				if (s[i] == ')') paraStack.pop();
				else return false;
				break;
			case '[':
				if (s[i] == ']') paraStack.pop();
				else return false;
				break;
			case '{':
				if (s[i] == '}') paraStack.pop();
				else return false;
				break;
			default: return false;
			}
		}
	}
	return paraStack.empty();
}

void Solution_423::test() {
	// write your test here

	// input
	string s;
	cin >> s;

	// algorithm and output;
	cout << isValidParentheses(s);
}