#include <iostream>
#include <vector>
#include "Solution_7.h"
using namespace std;

int main() {

	

	Solution_7 solution;

	TreeNode *tree = nullptr;
	string strTree;

	solution.createTree(tree);

	cout << solution.serializeDFS(tree);


	getchar();
	getchar();
}