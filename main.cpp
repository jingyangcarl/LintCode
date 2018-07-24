#include <iostream>
#include <vector>
#include "Solution_5.h"
using namespace std;

int main() {

	int a, b;
	vector<int> c;
	Solution_5 solution;
	
	cin >> a;
	while (cin >> b)	c.push_back(b);

	cout << solution.kthLargestElement_3(a, c) << endl;

	getchar();
	getchar();
}