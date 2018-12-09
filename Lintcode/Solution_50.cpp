#include "Solution_50.h"

vector<long long> Solution_50::productExcludeItself(vector<int>& nums) {
	// write your code here

	// Carl: 
	// Idea: 
	// division is not allowed, hence
	// do the double loop for each product except the index corresponsing element

	vector<long long> result;
	vector<int>::iterator iterI, iterJ;
	for (iterI = nums.begin(); iterI != nums.end(); iterI++) {
		long long product(1);
		for (iterJ = nums.begin(); iterJ != nums.end(); iterJ++) {
			product += iterI == iterJ ? 1 : *iterJ;
		}
		result.push_back(product);
	}
	return result;
}

void Solution_50::test() {
	// write your test here

}
