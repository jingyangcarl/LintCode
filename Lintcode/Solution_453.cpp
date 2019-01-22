#include "Solution_453.h"

void Solution_453::flatten(TreeNode * root) {
	// write your code here

	stack<TreeNode *> nodeStack;
	nodeStack.push(root);
	while (!nodeStack.empty()) {
		TreeNode * current = nodeStack.top();
		nodeStack.pop();
		if (current->right) nodeStack.push(current->right);
		if (current->left) {
			nodeStack.push(current->left);
			current->right = current->left;
			current->left = NULL;
		}
	}
}

void Solution_453::create(TreeNode * &root) {
	int num;
	cin >> num;
	if (num != -1) {
		root = new TreeNode(num);
		create(root->left);
		create(root->right);
	}
}

void Solution_453::preorderTraversal(TreeNode * root) {
	// write your code here
	if (root) {
		cout << root->val << ' ';
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
}

void Solution_453::test() {
	// write your test here

	// input;
	TreeNode * root(NULL);
	create(root);

	// algorithm
	flatten(root);

	// output
	preorderTraversal(root);
}