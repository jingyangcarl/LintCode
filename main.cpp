#include <iostream>
#include <vector>
#include "Solution_16.h"
using namespace std;

int main() {

	

	Solution_16 solution;

	int num;
	vector<int> nums;
	while (cin >> num) nums.push_back(num);

	solution.permuteUnique(nums);

	getchar();
	getchar();
	
}