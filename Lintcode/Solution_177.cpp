#include "Solution_177.h"

TreeNode * Solution_177::sortedArrayToBST(vector<int>& A) {
	// write your code here
	// Carl: try non-recursion
	// Idea: basically, the total nodes in this solution forms the question
	// which is the sum of the geometric progression with a1 = 1, and q = 2
	// where the formula should be sum = a1 * (1 - q^n) / (1 - q)
	// in this case, sum = 1 * (1 - 2^n) / (1 - 2)
	// which is sum = 2 ^n - 1;
	int totalLayer(1);
	while (pow(2, totalLayer) - 1 < A.size())
		totalLayer++;
	TreeNode * root = NULL;
	sortedArrayToBST(root, A, totalLayer, 1);
	return root;
	// ERROR: the order of the elements in the list should be ordered
}

TreeNode * Solution_177::sortedArrayToBST_2(vector<int>& A) {
	// write your code here
	int left(0), right(A.size() - 1);
	TreeNode * root = NULL;
	sortedArrayToBST_2(root, A, left, right);
	return root;
}

TreeNode * Solution_177::sortedArrayToBST_3(vector<int>& A) {
	// write your code here
	return sortedArrayToBST_3(A, 0, A.size() - 1);
}

void Solution_177::sortedArrayToBST(TreeNode * &root, vector<int> &A, int totalLayer, int currentLayer) {
	// write your code here
	if (currentLayer <= totalLayer) {
		if (!A.empty()) {
			root = new TreeNode(A.back());
			A.pop_back();
			sortedArrayToBST(root->left, A, totalLayer, currentLayer + 1);
			sortedArrayToBST(root->right, A, totalLayer, currentLayer + 1);
		}
	}
	// ERROR: the order of the elements in the list should be ordered
}

void Solution_177::sortedArrayToBST_2(TreeNode *& root, vector<int> A, int left, int right) {
	// write your code here
	if (left <= right) {
		int mid = (left + right) / 2;
		root = new TreeNode(A[mid]);
		sortedArrayToBST_2(root->left, A, left, mid - 1);
		sortedArrayToBST_2(root->right, A, mid + 1, right);
	}
}

TreeNode * Solution_177::sortedArrayToBST_3(vector<int> A, int left, int right) {
	// write your code here
	if (left <= right) {
		int mid = (left + right) / 2;
		TreeNode *root = new TreeNode(A[mid]);
		root->left = sortedArrayToBST_3(A, left, mid - 1);
		root->right = sortedArrayToBST_3(A, mid + 1, right);
		return root;
	}
	else return nullptr;
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
	TreeNode * root = sortedArrayToBST_3(A);

	// output;
	preorderTraversal(root);
}