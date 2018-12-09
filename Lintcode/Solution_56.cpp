#include "Solution_56.h"

vector<int> Solution_56::twoSum(vector<int>& numbers, int target) {
	// write your code here

	// Carl: 
	// Idea:
	// if there are two addents, there are only two ways of sum
	// in the first case, two addents are the same, which equal to half of the target
	// in the other, two addents, one of which should larger than the half of target, and the other should be smaller than that
	// however, both addents are in between zero and the target
	// then do the compare between small and large

	map<int, int> smallHalf, largeHalf;
	// <index, value>
	vector<int> result;

	// Carl: divide into small and large
	vector<int>::iterator iter;
	for (iter = numbers.begin(); iter != numbers.end(); iter++) {
		if (*iter < target / 2.0)
			smallHalf.insert(pair<int, int>(iter - numbers.begin(), *iter));
		else if (*iter > target / 2.0)
			largeHalf.insert(pair<int, int>(iter - numbers.begin(), *iter));
		else
			result.push_back(iter - numbers.begin());
	}

	// Carl: compare
	if (result.size() == 2)
		return result;
	else {
		map<int, int>::iterator iterSmall, iterLarge;
		result.clear();
		for (iterSmall = smallHalf.begin(); iterSmall != smallHalf.end(); iterSmall++) {
			for (iterLarge = largeHalf.begin(); iterLarge != largeHalf.end(); iterLarge++) {
				if ((*iterSmall).second + (*iterLarge).second == target) {
					if ((*iterSmall).first < (*iterLarge).first) {
						result.push_back((*iterSmall).first);
						result.push_back((*iterLarge).first);
					}
					else {
						result.push_back((*iterLarge).first);
						result.push_back((*iterSmall).first);
					}
					return result;
				}
			}
		}
	}
	
	result.push_back(-1);
	result.push_back(-1);
	return result;
}

vector<int> Solution_56::twoSum_2(vector<int>& numbers, int target) {
	// wirte your code here 

	// Carl: 
	// use map to save the complementary corresponding to eash elements

	map<int, int> complementation;
	// value index
	vector<int> result;

	vector<int>::iterator iter;
	for (iter = numbers.begin(); iter != numbers.end(); iter++) {
		if (complementation.count(target - *iter)) {
			result.push_back(complementation.at(target - *iter));
			result.push_back(iter - numbers.begin());
			return result;
		}
		complementation.insert(pair<int, int>(*iter, iter - numbers.begin()));
	}
	result.push_back(-1);
	result.push_back(-1);
	return result;
}

void Solution_56::test() {
	// write your test here 

	// Carl: input
	int n;
	cin >> n;
	vector<int> numbers;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		numbers.push_back(num);
	}

	// Carl: algorithm
	cin >> n;
	vector<int> result;
	result = twoSum_2(numbers, n);

	// Carl: output
	vector<int>::iterator iter;
	for (iter = result.begin(); iter != result.end(); iter++) {
		cout << *iter << " ";
	}
}
