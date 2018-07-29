#include <iostream>
#include <vector>
#include "Solution_24.h"
using namespace std;

int main() {

	LFUCache solution(3);

	solution.set(1, 10);
	solution.set(2, 20);
	solution.set(3, 30);
	cout << solution.get(1) << endl;
	solution.set(4, 40);
	cout << solution.get(4) << endl;
	cout << solution.get(3) << endl;
	cout << solution.get(2) << endl;
	cout << solution.get(1) << endl;
	solution.set(5, 50);
	cout << solution.get(1) << endl;
	cout << solution.get(2) << endl;
	cout << solution.get(3) << endl;
	cout << solution.get(4) << endl;
	cout << solution.get(5) << endl;

	getchar();
	getchar();
	
}