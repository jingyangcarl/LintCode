#include "Solution_9.h"

vector<string> Solution_9::fizzBuzz(int n) {

	vector<string> out;
	for (int i = 1; i <= n; i++) {
		if (i % 3 == 0 && i % 5 == 0) out.push_back("fizz buzz");
		else out.push_back(i % 3 == 0 ? "fizz" : i % 5 == 0 ? "buzz" : to_string(i));
	}
	return out;
}
