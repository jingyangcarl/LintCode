#include "Solution_41.h"

int Solution_41::maxSubArray(vector<int>& nums) {
	// write your code here

	// Carl:
	// start from the first element
	// the array consists of only positives and negatives
	// add all contiguous positives to posSum with initial value of 0
	// add all contiguous negatives to negSum with initial value of 0
	// compare posSum and negSum
	// if posSum >= -negSum, add elements to the sum all the way to the end of negative elements
	// else if posSum < -negSum, 
	//  if posSum != 0, add all positive elements to the sum, save the value and restart the counting from the next positive element
	//  else if posSum == 0, which means there is no positive value, then select the negatives with largest absolute value

	int sum(0), sumTemp(0);
	vector<int>::iterator iter, iterC;

	// Carl: boundary detection, data sample: [-1] or [3]
	if (nums.size() == 1) {
		return *nums.begin();
	}

	for (iter = nums.begin(); iter != nums.end(); iter++) {
		iterC = iter;

		// Carl: all the contiguous positive elements
		int posSum(0);
		while (iterC != nums.end() && *iterC >= 0) {
			posSum += *iterC;
			iterC++;
		}
		// Carl: all the contiguous negative elements
		int negSum(0);
		while (iterC != nums.end() && *iterC < 0) {
			negSum += *iterC;
			iterC++;
		}

		// Carl: compare posSum and negSum
		if (posSum != 0) {
			if (posSum >= -negSum) {
				for (iter; iter != iterC; iter++) {
					sumTemp += *iter;
				}
			}
			else {
				while (*iter >= 0) {
					sumTemp += *iter;
					iter++;
				}
				sum = sumTemp > sum ? sumTemp : sum;
				sumTemp = 0;
			}
		}
		else {
			int smallest(-65535);
			for (iter; iter != nums.end() && *iter < 0; iter++) {
				smallest = *iter > smallest ? *iter : smallest;
			}
			sum = smallest;
			sumTemp = 0;
		}
		// Carl: iteration compensation
		iter = --iterC;
	}

	// Carl: boundary detection, data sample [-1, 0, 1]
	if(sumTemp > 0)
		sum = sumTemp > sum ? sumTemp : sum;
	return sum;
}

void Solution_41::test() {
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
	n = maxSubArray(nums);

	// Carl: output
	cout << n << endl;
}