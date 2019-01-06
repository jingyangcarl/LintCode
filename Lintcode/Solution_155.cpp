#include "Solution_155.h"

int Solution::minDepth(TreeNode * root) {
	// write your code here
	return 0;
}

void Solution::create(TreeNode * root) {
	int i;
	cin >> i;
	if (i != -1) {
		root = new TreeNode(i);
		create(root->left);
		create(root->right);
	}
	else root = NULL;
}

void Solution::test() {
	// write your test here
	
	// input
	TreeNode * root;
	create(root);

	// algorithm and output
	cout << minDepth(root);
}
