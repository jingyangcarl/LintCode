#include "Solution_93.h"

bool Solution_93::isBalanced(TreeNode * root) {
	// write your code here
	if (!root) return true;
	if (abs(depth(root->left) - depth(root->right)) > 1) return false;
	return isBalanced(root->left) && isBalanced(root->right);
}

int Solution_93::depth(TreeNode * root) {
	// write your code here
	if (!root) return 0;
	else return 1 + max(depth(root->left), depth(root->right));
}

void Solution_93::create(TreeNode *& node) {
	int n;
	cin >> n;
	if (n != -1) {
		node = new TreeNode(n);
		create(node->left);
		create(node->right);
	}
	else return;
}

void Solution_93::inorderTraversal(TreeNode * root) {
	// write your code here
	if (root) {
		inorderTraversal(root->left);
		cout << root->val << " ";
		inorderTraversal(root->right);
	}
	else return;
}

void Solution_93::test() {
	// write your test here

	// input
	TreeNode *tree = NULL;
	create(tree);

	// algorithm and output
	cout << isBalanced(tree);
}
