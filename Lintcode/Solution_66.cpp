#include "Solution_66.h"

vector<int> Solution_66
::preorderTraversal(TreeNode * root) {
	// write your code here

	// Carl:
	// Idea:
	// recursion

	vector<int> nodes;
	preorderTraversal(root, nodes);
	return nodes;
}

void Solution_66::preorderTraversal(TreeNode * root, vector<int> &nodes) {
	// write your code here
	if (root) {
		nodes.push_back(root->val);
		preorderTraversal(root->left, nodes);
		preorderTraversal(root->right, nodes);
	}
	else return;
}

void Solution_66::create(TreeNode * &node) {
	int n;
	cin >> n;
	if (n != -1) {
		node = new TreeNode(n);
		create(node->left);
		create(node->right);
	}
	else return;
}

void Solution_66::test() {
	// write your test here
	
	// input
	TreeNode *tree = NULL;
	create(tree);

	// algorithm
	vector<int> nodes;
	nodes = preorderTraversal(tree);

	// output
	vector<int>::iterator iter;
	for (iter = nodes.begin(); iter != nodes.end(); iter++)
		cout << *iter << " ";
}