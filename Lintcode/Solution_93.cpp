#include "Solution_93.h"

bool Solution::isBalanced(TreeNode * root) {
	// write your code here
	int leftHeight(0), rightHeight(0);
	bool is(false);
}

void Solution::isBalanced(TreeNode * root, int leftHeight, int rightHeight, bool is) {
	// write your code here
	if (root) {
		if (abs(leftHeight - rightHeight) > 1) is = false;
		isBalanced(root->left, leftHeight + 1, rightHeight, is);
		isBalanced(root->right, leftHeight, rightHeight + 1, is);
	}
	else return;
}

void Solution::create(TreeNode *& node) {
	int n;
	cin >> n;
	if (n != -1) {
		node = new TreeNode(n);
		create(node->left);
		create(node->right);
	}
	else return;
}

void Solution::inorderTraversal(TreeNode * root) {
	// write your code here
	if (root) {
		inorderTraversal(root->left);
		cout << root->val << " ";
		inorderTraversal(root->right);
	}
	else return;
}

void Solution::test() {
	// write your test here

	// input
	TreeNode *tree = NULL;
	create(tree);
	int n;
	cin >> n;
	TreeNode *node = new TreeNode(n);

	// algorithm

	// output
	inorderTraversal(tree);
}
