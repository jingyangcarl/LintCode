#include <iostream>
#include <vector>
#include "Solution_14.h"
using namespace std;

int main() {

	

	Solution_14 solution;
	vector<int> nums;
	int num, a;
	cin >> a;
	while (cin >> num) nums.push_back(num);

	cout << solution.binarySearch(nums, a) << endl;

	getchar();
	getchar();
	
}