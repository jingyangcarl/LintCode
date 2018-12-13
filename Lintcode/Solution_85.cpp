#include "Solution_85.h"

TreeNode * Solution_85::insertNode(TreeNode * root, TreeNode * node) {
	// write your code here

	return insertNode(root, node);

}

void Solution_85::insertNode(TreeNode *& root, TreeNode * node) {
	// write your code here

}

void Solution_85::create(TreeNode *& node) {
	int n;
	cin >> n;
	if (n != -1) {
		node = new TreeNode(n);
		create(node->left);
		create(node->right);
	}
	else return;
}

void Solution_85::test() {
	// write your test here

	// input
	TreeNode *tree = NULL;
	create(tree);

	// algorithm

	// output
}


