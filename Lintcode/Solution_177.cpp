#include "Solution_177.h"

TreeNode * Solution_177::sortedArrayToBST(vector<int>& A) {
	// write your code here

	TreeNode * root;
	sortedArrayToBEST(root, A, 0, A.size() - 1);

	return nullptr;
}

void Solution_177::sortedArrayToBEST(TreeNode *& root, vector<int> A, int left, int right) {
	// write your code here
	if (left >= right) {
	}
}

void Solution_177::preorderTraversal(TreeNode * root) {
	// write your code here
	if (root) {
		cout << root->val << ' ';
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
}

void Solution_177::test() {
	// write your test here
	
	// intput
	vector<int> A;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		A.push_back(num);
	}

	// algorithm
	TreeNode * root = sortedArrayToBST(A);

	// output;
	preorderTraversal(root);
}
