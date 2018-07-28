#include <iostream>
#include <vector>
#include "Solution_17.h"
using namespace std;

int main() {

	

	Solution_17 solution;

	int num;
	vector<int> nums;
	while (cin >> num) nums.push_back(num);

	solution.subsets(nums);

	getchar();
	getchar();
	
}