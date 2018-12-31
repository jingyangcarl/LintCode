#include "Solution_128.h"

int Solution_128::hashCode(string & key, int HASH_SIZE) {
	// write your code here

	long long sum(0);
	vector<long long> factor(key.size(), 1);

	for (int i = 0; i < key.size(); i++)
		factor[i] = pow(33, i);

	for (int i = 0; i < key.size(); i++)
		sum += factor[i] * (int)key[-i + key.size() - 1];

	return sum % HASH_SIZE;

	// ERROR: "abcdefghijklmnopqrstuvwxyz"
	// 2607
	// which is because the overflow
}

int Solution_128::hashCode_2(string & key, int HASH_SIZE) {
	// write your code here

	// Carl: 
	// Idea: 
	// if the string is too long, the accumulation of the product will be increated in a power level
	// which will lead to the overflow of an int or evel a longlong
	// however, the digits larger than HASH_SIZE will not be counted in the calculation
	// hence, do the module every time when calculate the powers

	long long sum(0);
	vector<long long> factor(key.size(), 1);

	for (int i = 1; i < key.size(); i++)
		factor[i] = factor[i - 1] * 33 % HASH_SIZE;

	for (int i = 0; i < key.size(); i++)
		sum += factor[i] * (int)key[-i + key.size() - 1];

	return sum % HASH_SIZE;
}

void Solution_128::test() {
	// write your test here
	
	// input
	string key;
	cin >> key;
	int HASH_SIZE;
	cin >> HASH_SIZE;

	// algorithm and output
	cout << hashCode_2(key, HASH_SIZE);
}
