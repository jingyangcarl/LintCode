#include "Solution_375.h"

TreeNode * Solution_375::cloneTree(TreeNode * root) {
	// write your code here
	TreeNode *copy(NULL);
	cloneTree(root, copy);
	return copy;
}

TreeNode * Solution_375::cloneTree_2(TreeNode * root) {
	// write your code here
	
	// Idea: try non-recursion
	return nullptr;
}

void Solution_375::cloneTree(TreeNode * root, TreeNode * &copy) {
	// write your code here
	if (root) {
		copy = new TreeNode(root->val);
		cloneTree(root->left, copy->left);
		cloneTree(root->right, copy->right);
	}
}

void Solution_375::create(TreeNode *& root) {
	int num;
	cin >> num;
	if (num != -1) {
		root = new TreeNode(num);
		create(root->left);
		create(root->right);
	}
}

void Solution_375::preorderTraversal(TreeNode * root) {
	if (root) {
		cout << root->val << ' ';
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
}

void Solution_375::test() {
	// write your test here

	// input
	TreeNode *root;
	create(root);

	// algorithm;
	TreeNode *copy = cloneTree(root);

	// output
	preorderTraversal(copy);
}
