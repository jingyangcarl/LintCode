#include <iostream>
#include "Solution_29.h"
using namespace std;

int main() {

	Solution_29 solution;

	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;

	cout << solution.isInterleave(s1, s2, s3);

}