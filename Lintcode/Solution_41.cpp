#include "Solution_41.h"

int Solution_41::maxSubArray(vector<int> &nums) {
	// write your code here

	// Carl:
	// start from the first element
	// if the next element is positive or zero, add in the array
	// if the next element is negative, the following procesures depend on the next positive elements until the next negative
	//  if the absolute value of the on-coming negatives are larger than the sum of all on-coming positive elements, break the array, save and go on;
	//  if the absolute value fo the on-coming negatives are smaller or equal than the sum of all on-comming positive elements, add the elements

	int sum(0), sumTemp(0);
	vector<int>::iterator iter, iterC;

	// Carl: if the first element is negative, remove it
	if (nums.at(0) < 0)
		nums.erase(nums.begin());

	for (iter = nums.begin(); iter != nums.end(); iter++) {
		if (*iter >= 0) {
			// Carl: if the next element is positive or equal to 0
			sumTemp += *iter;
		}
		else {
			// Carl: if the next element is negative
			iterC = iter;

			// Carl: all the contiguous negative elements
			int negSum(0);
			while (*iterC < 0) {
				negSum += *iterC;
				iterC++;
			}
			// Carl: all the contiguous positive elements
			int posSum(0);
			while (*iterC >= 0) {
				posSum += *iterC;
				iterC++;
			}

			// Carl: compare
			if (-negSum <= posSum) {
				// Carl: add all the passed elements
				for (iter; iter != iterC; iter++) {
					sumTemp += *iter;
				}
			}
			else {
				// Carl: save and restart detection
				sum = sumTemp > sum ? sumTemp : sum;
				iter = iterC;
				sumTemp = 0;
			}
		}
	}

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