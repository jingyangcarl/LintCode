#include "Solution_12.h"

Solution_12::Solution_12() {
	// do intialization if necessary
	minData = 65535;
}

void Solution_12::push(int number) {
	// write your code here
	data.push_back(number);
	if (number < minData) {
		minData = number;
		minIndex.push(data.size()-1);
	}
}

int Solution_12::pop() {
	// write your code here
	int popNum = data.at(data.size() - 1);
	if (data.size() - 1 == minIndex.top()) {
		minIndex.pop();
		if(!minIndex.empty()) minData = data.at(minIndex.top());
		else minData = 65535;
	}
	data.pop_back();
	return popNum;
}

int Solution_12::min() {
	// write your code here
	return minData;
}
