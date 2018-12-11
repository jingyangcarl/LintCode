#include "Solution_67.h"

vector<int> Solution_67::inorderTraversal(TreeNode * root) {
	// write your code here
	vector<int> nodes;
	inorderTraversal(root, nodes);
	return nodes;
}

void Solution_67::inorderTraversal(TreeNode * root, vector<int>& nodes) {
	// write your code here
	if (root) {
		inorderTraversal(root->left, nodes);
		nodes.push_back(root->val);
		inorderTraversal(root->right, nodes);
	}
	else return;
}

void Solution_67::create(TreeNode *& node) {
	int n;
	cin >> n;
	if (n != -1) {
		node = new TreeNode(n);
		create(node->left);
		create(node->right);
	}
	else return;
}

void Solution_67::test() {
	// write your test here

	// input
	TreeNode *tree = NULL;
	create(tree);

	// algorithm
	vector<int> nodes;
	nodes = inorderTraversal(tree);

	// output
	vector<int>::iterator iter;
	for (iter = nodes.begin(); iter != nodes.end(); iter++)
		cout << *iter << " ";
}
