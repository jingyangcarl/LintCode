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

int Solution_46::majorityNumber_2(vector<int>& nums) {
	// write your code here

	// Carl:
	// Idea:
	// as illustrated in the description, the majority number should have a count larger than the half of the size of the array
	// and except the maority number, there will be no other number have a total count larger than the half of the size of the array
	// compared with majorityNumber(), the maxCount, and maxNum loop can be eliminated

	map<int, int> numMap;
	for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++) {
		if (numMap.find(*iter) == numMap.end())
			numMap.insert(pair<int, int>(*iter, 1));
		else {
			(*numMap.find(*iter)).second++;
			if ((*numMap.find(*iter)).second > nums.size() / 2)
				return (*numMap.find(*iter)).first;
		}
	}

	return 0;
}

int Solution_46::majorityNumber_3(vector<int>& nums) {
	// write your code here

	// Carl: 
	// Idea: 
	// based on the majorityNumber_2, 
	// a map can be replaced by an array, where the index represents the number, and the element in the array represents the counts

	int array[65535];
	for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++) {
		if ((++array[*iter]) > nums.size() / 2)
			return *iter;
	}

	return 0;
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
	n = majorityNumber_2(nums);

	// Carl: output
	cout << n << endl;
}