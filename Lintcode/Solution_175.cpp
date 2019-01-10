#include "Solution_175.h"

void Solution_175::invertBinaryTree(TreeNode * root) {
	// write your code here
	if (root) {
		invertBinaryTree(root->left);
		invertBinaryTree(root->right);
		
		// swap
		TreeNode * temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
}

void Solution_175::create(TreeNode *& root) {
	int num;
	cin >> num;
	if (num == -1) root = NULL;
	else {
		root = new TreeNode(num);
		create(root->left);
		create(root->right);
	}
}

void Solution_175::preorderTraversal(TreeNode * root) {
	if (root) {
		cout << root->val << ' ';
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
}

void Solution_175::test() {
	// write your test here

	// input
	TreeNode *root;
	create(root);

	// algorithm;
	invertBinaryTree(root);

	// output;
	preorderTraversal(root);
}
