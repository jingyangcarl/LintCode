#include "Solution_4.h"
#include <set>
using namespace std;

int Solution_4::nthUglyNumber(int n){
	set<int> uglyNumber;
	uglyNumber.insert(1);

	for (int i = 1; i <= n; i++) {
		uglyNumber.insert(2 * i);
		if (i <= n / 3.0*2.0) uglyNumber.insert(3 * i);
		if (i <= n / 5.0*2.0) uglyNumber.insert(5 * i);
	}

	set<int>::iterator iter = uglyNumber.begin();
	for (int i = 1; i < n; i++)	iter++;
	return *iter;

	// Carl: error input 20, expected 36
}

int Solution_4::nthUglyNumber_2(int n) {

	// Carl: the ugly numbers are created by the least number in the list times 2, 3, 5
	set<long long> uglyNumber;
	uglyNumber.insert(1);
	long long currentFactor = 1;

	for (int i = 0; i < n; i++) {
		uglyNumber.insert(currentFactor * 2);
		uglyNumber.insert(currentFactor * 3);
		uglyNumber.insert(currentFactor * 5);
		set<long long>::iterator iter = uglyNumber.begin();
		while (*iter <= currentFactor) iter++;
		currentFactor = *iter;
	}

	set<long long>::iterator iter = uglyNumber.begin();
	for (int i = 1; i < n; i++) iter++;

	return *iter;
}