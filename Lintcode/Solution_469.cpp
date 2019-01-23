#include "Solution_469.h"

bool Solution_469::isIdentical(TreeNode * a, TreeNode * b) {
	// write your code here

	bool same(true);
	isIdentical(a, b, same);
	return same;
}

void Solution_469::isIdentical(TreeNode * a, TreeNode * b, bool &same) {
	// write your code here
	if (!same) return;
	if (a && b) {
		if (a->val != b->val) same = false;
		isIdentical(a->left, b->left, same);
		isIdentical(a->right, b->right, same);
	}
	else if (a || b) same = false;
}

void Solution_469::create(TreeNode *& root) {
	int num;
	cin >> num;
	if (num != -1) {
		root = new TreeNode(num);
		create(root->left);
		create(root->right);
	}
}

void Solution_469::preorderTraversal(TreeNode * root) {
	if (root) {
		cout << root->val << ' ';
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
}

void Solution_469::test() {
	// write your test here

	// intput
	TreeNode *a(NULL), *b(NULL);
	create(a);
	create(b);

	// algorithm and output
	cout << isIdentical(a, b);
}
