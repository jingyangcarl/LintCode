#include "Solution_3.h"

int Solution_3::digitCounts(int k, int n) {

	// Carl: if count 2 between 0 and 99, which are 100 numbers
	// Carl: 100/100 = 1, 1/10 = 0, 0*100 = 0 twos on hundred
	// Carl: 100/10 = 10, 10/10 = 1, 1*10 = 10 twos on ten
	// Carl: 100/1 = 100, 100/10 = 10, 10*1 = 10 twos on one

	int N(n);
	while (N % 10 != 0) N--;

	return 0;
}