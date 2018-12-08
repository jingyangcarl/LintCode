#include "Solution_46.h"

int Solution_46::majorityNumber(vector<int>& nums) {
	// write your code here

	map<int, int> numMap;

	for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++) {
		if (numMap.find(*iter) == numMap.end())
			numMap.insert(pair<int, int>(*iter, 1));
		else
			(*numMap.find(*iter)).second++;
	}

	int maxCount(INT_MIN), maxNum(INT_MIN);
	for (map<int, int>::iterator iter = numMap.begin(); iter != numMap.end(); iter++) {
		if ((*iter).second > maxCount) {
			maxCount = (*iter).second;
			maxNum = (*iter).first;
		}
	}

	return maxNum;
}

void Solution_46::test() {
	// write your test here

	// Carl: input
	int n;
	cin >> n;
	vector<int> nums;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		nums.push_back(num);
	}

	// Carl: algorithm
	n = majorityNumber(nums);

	// Carl: output
	cout << n << endl;
}