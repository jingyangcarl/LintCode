#include <iostream>
#include <vector>
#include "Solution_12.h"
using namespace std;

int main() {

	

	Solution_12 solution;

	solution.push(1);
	cout << solution.pop() << endl;
	solution.push(2);
	solution.push(3);
	cout << solution.min() << endl;
	solution.push(1);
	cout << solution.min() << endl;

	getchar();
	getchar();
	
}