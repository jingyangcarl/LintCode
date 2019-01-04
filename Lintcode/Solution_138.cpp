#include "Solution_138.h"

vector<int> Solution_138::subarraySum(vector<int>& nums) {
	// write your code here

	vector<int> pair;
	for (int i = 0; i < nums.size(); i++) {
		int sum(0);
		for (int j = i; j < nums.size(); j++) {
			sum += nums[j];
			if (!sum) {
				pair.push_back(i);
				pair.push_back(j);
			}
		}
	}

	return pair;
}

vector<int> Solution_138::subarraySum_2(vector<int>& nums) {
	// write your code here

	// Carl:
	// Idea:
	// do the sum from the first element to each for accumulation
	// if there the sum of the subarray is zero
	// there will be two sum with the same value
	// find the two sum;
	// array: 1 -1 2
	// sum:   1 0 2
	// array: 1 -3 1 2 -3 4
	// sum:   1 -2 -1 1 -2 2

	// do the sum from first to each elements
	// if there is a zero in the sum, then return first element and current index
	// else return next index of repeated element and the current
	map<int, int> sums; // index, sum
	vector<int> index(2, 0);
	nums.push_back(1);
	int sum(0);
	for (int i = 0; i < nums.size(); i++) {
		sum += nums.at(i);
		if (!sum) {
			index[1] = i;
			return index;
		}
		else {
			map<int, int>::iterator iter = sums.find(sum);
			if (iter != sums.end()) {
				index[0] = (*iter).second+1;
				index[1] = i;
				return index;
			}
			sums.insert(pair<int, int>(sum, i));
		}
	}
}

void Solution_138::test() {
	// write your test here

	// input
	int n;
	cin >> n;
	vector<int> nums;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		nums.push_back(num);
	}

	// algorithm
	nums = subarraySum_2(nums);

	// output;
	cout << nums[0] << ' ' << nums[1] << endl;
}