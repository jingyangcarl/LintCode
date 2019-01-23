#include "Solution_474.h"

ParentTreeNode * Solution_474::lowestCommonAncestorII(ParentTreeNode * root, ParentTreeNode * A, ParentTreeNode * B) {
	// write your code here

	getchar();

	return nullptr;
}

void Solution_474::create(ParentTreeNode *& root, ParentTreeNode * parent) {
	int num;
	cin >> num;
	if (num != -1) {
		root = new ParentTreeNode();
		root->val = num;
		root->parent = parent;
		create(root->left, root);
		create(root->right, root);
	}
}

void Solution_474::preorderTraversal(ParentTreeNode * root) {
	if (root) {
		cout << root->val << ' ';
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
}

void Solution_474::test() {
	// write your test here

	// input
	ParentTreeNode *root(NULL);
	create(root, NULL);
	ParentTreeNode *A, *B;
	A = new ParentTreeNode();
	cin >> A->val;
	B = new ParentTreeNode();
	cin >> B->val;

	// algorithm
	ParentTreeNode *node = lowestCommonAncestorII(root, A, B);

	// output
	cout << node->val << endl;
}
