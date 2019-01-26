#include "Solution_495.h"

void Stack::push(int x) {
	// write your code here
	data.push_back(x);
}

void Stack::pop() {
	// write your code here
	data.pop_back();
}

int Stack::top() {
	// write your code here
	return data.back();
}

bool Stack::isEmpty() {
	// write your code here
	return data.empty();
}

void Stack::test() {
}
