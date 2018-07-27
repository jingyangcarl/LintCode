#include <iostream>
#include <vector>
#include "Solution_15.h"
using namespace std;

int main() {

	

	Solution_15 solution;

	int num;
	vector<int> nums;
	while (cin >> num) nums.push_back(num);

	solution.permute(nums);

	getchar();
	getchar();
	
}