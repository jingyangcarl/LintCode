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
	return 0;
}

void Solution_128::test() {
	// write your test here
	
	// input
	string key;
	cin >> key;
	int HASH_SIZE;
	cin >> HASH_SIZE;

	// algorithm and output
	cout << hashCode(key, HASH_SIZE);
}
