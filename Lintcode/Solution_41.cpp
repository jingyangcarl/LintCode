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
			if (posSum > -negSum) {
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
	if (sumTemp > 0)
		sum = sumTemp > sum ? sumTemp : sum;
	return sum;

	// error when input
	// 1000
	// -28 - 75 100 - 26 - 80 - 26 - 47 63 59 - 84 - 54 48 64 - 34 - 48 80 38 - 76 25 17 - 59 - 10 - 67 80 80 - 63 - 66 5 97 - 34 - 28 60 59 - 64 - 9 - 45 - 15 27 - 2 78 - 61 - 54 - 44 - 15 66 79 53 - 70 11 36 - 3 - 54 27 - 16 81 88 77 - 5 - 67 82 19 - 96 - 50 - 17 - 33 0 58 78 - 34 95 75 53 66 45 51 22 - 74 - 32 - 40 - 60 92 21 4 - 82 - 38 - 75 19 - 90 67 10 52 100 - 66 - 39 91 - 5 39 - 59 74 9 - 37 - 88 60 40 - 2 43 - 63 - 33 35 49 - 53 32 20 - 100 42 69 49 36 42 - 26 - 25 70 27 - 71 - 28 94 - 30 - 61 12 21 - 77 - 35 69 2 - 90 59 - 13 - 37 56 7 90 - 41 - 27 - 49 - 59 40 39 - 80 17 - 55 - 54 33 87 55 - 51 - 32 8 52 2 59 67 - 1 31 42 87 94 - 65 53 - 10 31 58 81 34 - 30 2 51 - 37 73 48 71 - 78 - 28 - 62 41 68 25 - 3 57 - 58 11 - 92 33 85 47 - 49 79 - 7 - 53 8 - 41 - 66 65 47 11 0 - 92 18 41 - 91 - 26 - 82 - 78 13 - 1 - 67 - 56 34 - 20 2 - 54 - 58 - 77 90 90 - 67 29 16 24 - 20 49 - 97 67 - 9 18 10 62 88 - 31 - 24 36 6 53 - 54 - 99 - 94 - 95 26 79 47 34 88 94 - 95 68 - 88 - 80 41 1 - 34 60 - 95 78 - 81 83 - 64 - 5 - 25 - 87 - 81 - 30 75 36 - 14 - 19 - 98 46 - 94 - 36 - 38 51 - 48 - 91 - 39 - 50 - 33 98 49 81 63 - 59 - 37 32 4 - 54 - 23 - 38 88 89 - 16 - 30 90 63 - 52 - 20 74 82 - 34 87 - 86 21 - 41 93 82 - 96 20 - 75 96 52 - 72 87 45 83 63 - 24 - 86 - 88 85 12 - 8 77 - 56 - 51 - 73 43 - 34 35 - 10 65 54 1 - 60 100 36 8 - 81 53 81 42 75 - 44 83 55 - 24 96 - 31 - 43 42 - 37 - 51 - 33 40 15 - 83 - 92 - 77 - 35 - 68 21 - 64 - 12 22 - 71 - 19 - 13 - 15 15 56 - 8 79 - 44 - 9 - 78 - 11 - 28 - 13 42 38 - 7 - 48 - 90 70 69 2 - 47 56 - 93 - 16 51 44 - 1 - 93 64 - 13 67 - 72 95 80 1 68 - 47 37 72 - 29 - 74 79 - 60 97 12 - 38 7 - 75 26 90 99 46 - 3 - 5 74 9 - 26 60 - 55 85 - 52 - 15 - 24 3 23 44 5 - 55 72 54 97 53 49 - 30 18 36 99 23 79 94 - 15 - 84 - 35 86 8 16 1 - 23 83 - 47 - 67 6 13 8 84 57 - 80 67 38 - 95 65 - 46 - 87 34 97 - 29 - 70 55 17 - 92 87 - 39 - 82 74 5 38 - 81 - 9 41 66 49 - 38 - 42 88 - 65 - 83 45 - 52 - 34 54 - 39 - 50 - 45 - 62 35 - 26 - 74 20 - 22 92 - 67 51 77 42 58 40 - 86 44 13 100 - 62 52 - 49 - 72 - 68 - 13 47 57 21 63 - 54 52 - 8 31 - 87 - 34 - 29 - 7 45 - 32 95 47 - 31 - 10 - 15 9 - 76 - 69 - 15 21 - 26 79 - 64 43 72 29 - 90 6 - 29 - 15 - 53 - 40 - 3 - 7 - 91 - 80 0 - 91 5 - 72 55 - 88 - 31 - 43 33 - 17 - 4 23 - 89 26 - 29 5 - 26 - 4 - 28 22 - 36 45 31 36 - 1 - 35 - 45 22 - 67 - 85 22 80 - 10 - 38 - 14 - 93 - 13 27 64 75 89 75 10 - 23 - 78 41 3 54 73 - 73 - 28 - 61 - 48 7 - 8 - 16 62 - 74 50 38 - 74 - 23 22 3 66 22 - 36 - 59 17 - 54 - 45 80 - 66 86 3 5 66 28 73 63 17 5 - 58 - 87 - 15 - 36 55 - 34 - 39 93 55 - 74 - 40 13 - 70 89 - 10 75 - 24 86 76 15 28 - 66 - 55 8 25 24 98 - 47 25 - 29 - 44 - 54 - 48 - 80 89 98 27 - 73 - 44 35 - 64 84 7 - 39 - 57 30 100 12 41 - 17 - 27 - 25 7 78 - 10 50 - 41 - 55 - 34 21 88 27 21 32 58 - 93 18 - 55 61 - 79 17 - 27 82 - 29 36 - 22 - 12 31 49 - 1 24 - 63 67 41 24 98 66 8 - 2 100 - 3 - 44 55 75 - 46 16 - 34 - 38 - 87 - 21 - 27 39 18 23 - 64 - 99 43 74 11 - 67 4 - 96 - 56 88 4 - 45 27 - 79 - 39 - 97 - 14 44 12 - 12 57 - 81 - 37 38 89 - 75 - 79 - 42 - 43 - 18 - 91 39 - 23 - 90 - 20 - 32 92 96 99 - 11 - 7 - 17 - 39 - 23 45 58 - 73 73 - 14 60 61 - 6 - 67 - 16 72 - 91 - 51 57 - 99 - 9 82 32 - 39 - 40 23 - 78 - 45 27 - 65 100 91 - 96 - 1 - 72 - 9 - 47 9 87 55 39 79 - 42 - 26 - 3 48 22 - 52 - 71 - 77 - 30 12 38 84 - 6 39 67 97 77 - 82 75 - 45 11 - 81 - 89 60 51 - 48 - 99 - 31 - 75 51 82 - 31 - 39 - 77 98 88 66 - 37 - 3 - 96 - 83 - 86 - 27 80 - 93 - 55 44 - 14 98 - 86 - 4 90 - 51 - 64 71 - 91 - 4 - 4 - 99 - 57 - 93 27 - 15 - 89 21 - 77 9 39 - 80 3 10 65 4 26 27 11 - 63 2 - 36 - 81 4 - 57 - 93 - 53 - 92 - 44 94 - 63 90 56 40 - 32 - 28 - 1 - 36 - 70 51 1 80 - 9 100 - 46 - 69 - 93 59 - 82 - 34 - 58 - 90 78 - 61 34 33 - 37 6 66 - 49 92 98 - 57 - 79 - 60 - 4 91 95 - 85 - 83 - 69 - 82 4 - 100 44 - 67 92 - 79 16 83 - 70 84 57 90 - 30 - 98 - 24 - 48 100 17 - 1 - 52 - 4 - 28 39 - 43 28 12 - 14 - 52 - 64 - 84 6 66 - 98 - 73 - 72
}

int Solution_41::maxSubArray_2(vector<int>& nums) {
	// write your code here

	// Carl: 
	// do a double loop
	// calculate the largest sum
	// if the sum == 0, means no positives, then select the largest negative element

	int sum(0), tempSum(0);
	vector<int>::iterator iterI, iterJ;

	for (iterI = nums.begin(); iterI != nums.end(); iterI++) {
		tempSum = 0;

		for (iterJ = iterI; iterJ != nums.end(); iterJ++) {
			tempSum += *iterJ;

			sum = tempSum > sum ? tempSum : sum;
		}
	}

	if (sum == 0) {
		sum = -65536;
		for (iterI = nums.begin(); iterI != nums.end(); iterI++) {
			sum = *iterI > sum ? *iterI : sum;
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
	n = maxSubArray_2(nums);

	// Carl: output
	cout << n << endl;
}