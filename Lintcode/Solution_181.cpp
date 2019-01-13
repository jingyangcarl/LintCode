#include "Solution_181.h"

int Solution_181::bitSwapRequired(int a, int b) {
	// write your code here
	
	// Carl: 
	// a Xor b will generate a result bits where bits required to flip will be noticed as 1
	return bitset<32>(a^b).count();
}

void Solution_181::test() {
	// wirte your test here
	
	// input
	int a, b;
	cin >> a >> b;

	// algorithm and output;
	cout << bitSwapRequired(a, b);
}
