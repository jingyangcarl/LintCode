#include <iostream>
#include <vector>
#include "Solution_11.h"
using namespace std;

int main() {

	

	Solution_11 solution;
	
	TreeNode *root = nullptr;
	vector<int> result;
	vector<int>::iterator iter;
	solution.createTree(root);

	int k1, k2;
	cin >> k1 >> k2;
	result = solution.searchRange(root, k1, k2);
	for (iter = result.begin(); iter != result.end(); iter++)
		cout << *iter++ << " ";

	getchar();
	getchar();
	
}