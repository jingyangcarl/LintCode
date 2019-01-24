#include "Solution_474.h"

ParentTreeNode * Solution_474::lowestCommonAncestorII(ParentTreeNode * root, ParentTreeNode * A, ParentTreeNode * B) {
	// write your code here

	vector<ParentTreeNode *> traceA, traceB;
	ParentTreeNode *p(NULL);
	p = A;
	while (p) {
		traceA.push_back(p);
		p = p->parent;
	}
	p = B;
	while (p) {
		traceB.push_back(p);
		p = p->parent;
	}

	ParentTreeNode * current(NULL);
	while (!traceA.empty() && !traceB.empty()) {
		if (traceA.back() == traceB.back()) {
			current = traceA.back();
			traceA.pop_back();
			traceB.pop_back();
		}
		else break;
	}
	return current;
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

void Solution_474::preorderFind(ParentTreeNode * root, int val, ParentTreeNode *& node) {
	if (root) {
		if (root->val == val) node = root;
		preorderFind(root->left, val, node);
		preorderFind(root->right, val, node);
	}
}

void Solution_474::test() {
	// write your test here

	// input
	ParentTreeNode *root(NULL);
	create(root, NULL);
	ParentTreeNode *A, *B;
	int val;
	cin >> val;
	preorderFind(root, val, A);
	cin >> val;
	preorderFind(root, val, B);

	// algorithm
	ParentTreeNode *node = lowestCommonAncestorII(root, A, B);

	// output
	cout << node->val << endl;
}
