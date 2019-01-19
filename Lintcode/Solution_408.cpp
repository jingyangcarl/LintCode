#include "Solution_408.h"

string Solution_408::addBinary(string & a, string & b) {
	// write your code here
	string c;
	bool carry(false);
	string::reverse_iterator ia(a.rbegin()), ib(b.rbegin());

	while (ia != a.rend() && ib != b.rend()) {
		c = (char)(((*ia - '0' + *ib - '0' + carry) % 2) + '0') + c;
		carry = (*ia - '0' + *ib - '0' + carry >= 2) ? true : false;
		ia++; ib++;
	}

	while (ia != a.rend()) {
		c = (char)(((*ia - '0' + carry) % 2) + '0') + c;
		carry = (*ia - '0' + carry >= 2) ? true : false;
		ia++;
	}

	while (ib != b.rend()) {
		c = (char)(((*ib - '0' + carry) % 2) + '0') + c;
		carry = (*ib - '0' + carry >= 2) ? true : false;
		ib++;
	}

	if (carry) c = '1' + c;

	return c;
}

void Solution_408::test() {
	// write your code here

	// input
	string a, b;
	cin >> a >> b;

	// algorithm and output
	 cout << addBinary(a, b);
}
