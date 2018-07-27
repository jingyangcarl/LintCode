#pragma once
#include <vector>
#include <stack>
using namespace std;

class Solution_12 {
public:
	Solution_12();

	/*
	* @param number: An integer
	* @return: nothing
	*/
	void push(int number);

	/*
	* @return: An integer
	*/
	int pop();

	/*
	* @return: An integer
	*/
	int min();

private:
	vector<int> data;
	stack<int> minIndex;
	int minData;

};