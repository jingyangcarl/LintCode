#pragma once
#include <vector>
using namespace std;

class Stack {
public:
	vector<int> data;

	/*
	 * @param x: An integer
	 * @return: nothing
	 */

	void push(int x);

	/*
	 * @return: nothing
	 */
	void pop();

	/*
	 * @return: An integer
	 */
	int top();

	/*
	 * @return: True if the stack is empty
	 */
	bool isEmpty();

	void test();
};