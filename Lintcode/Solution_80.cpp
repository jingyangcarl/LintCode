#include "Solution_80.h"

int Solution_80::median(vector<int>& nums) {
	// write your code here
	sort(nums.begin(), nums.end());
	return nums.size() % 2 ? nums.at((nums.size() - 1) / 2) : nums.at(nums.size() / 2 - 1);
}

void Solution_80::test() {
	// write your test here
	int n;
	cin >> n;

}
