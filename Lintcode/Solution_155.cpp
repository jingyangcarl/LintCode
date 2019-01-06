#include "Solution_155.h"

int Solution_155::minDepth(TreeNode * root) {
	// write your code here

	int curDep(0), minDep(INT_MAX);
	minDepth(root, curDep, minDep);
	return minDep;
}

void Solution_155::minDepth(TreeNode * root, int curDep, int &minDep) {
	// write your code here
	if (!root) {
		// if this is a leaf node, do the comparison
		minDep = curDep < minDep ? curDep : minDep;
	}
	else {
		minDepth(root->left, curDep + 1, minDep);
		minDepth(root->right, curDep + 1, minDep);
	}
}

void Solution_155::create(TreeNode * &root) {
	int i;
	cin >> i;
	if (i != -1) {
		root = new TreeNode(i);
		create(root->left);
		create(root->right);
	}
	else root = NULL;
}

void Solution_155::test() {
	// write your test here
	
	// input
	TreeNode * root(NULL);
	create(root);

	// algorithm and output
	cout << minDepth(root);
}
