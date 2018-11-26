#include "Solution_11.h"

vector<int> Solution_11::searchRange(TreeNode * root, int k1, int k2) {

	vector<int> result;
	searchRange(root, result, k1, k2);
	return result;
}

void Solution_11::searchRange(TreeNode * root, vector<int> &result, int k1, int k2) {

	if (root == nullptr) return;
	else {
		if(root->val >= k1 && root->val <= k2) result.push_back(root->val);
		searchRange(root->left, result, k1, k2);
		searchRange(root->right, result, k1, k2);
	}
}

void Solution_11::createTree(TreeNode *&root) {

	string i;
	cin >> i;

	if (i != "#") {
		root = new TreeNode(stoi(i));
		createTree(root->left);
		createTree(root->right);
	}
}
