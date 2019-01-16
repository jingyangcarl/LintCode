#include "Solution_376.h"

vector<vector<int>> Solution_376::binaryTreePathSum(TreeNode * root, int target) {
	// write your code here
	vector<vector<int>> paths;
	vector<int> currentPath;
	if (!root) return paths;
	binaryTreePathSum(root, target, 0, paths, currentPath);
	return paths;
}

void Solution_376::binaryTreePathSum(TreeNode * root, int target, int current, vector<vector<int>>& paths, vector<int> &currentPath) {
	if (root && current < target) {
		currentPath.push_back(root->val);
		if (current + root->val == target)
			paths.push_back(currentPath);
		binaryTreePathSum(root->left, target, current + root->val, paths, currentPath);
		binaryTreePathSum(root->right, target, current + root->val, paths, currentPath);
		currentPath.pop_back();
	}
}

void Solution_376::create(TreeNode *& root) {
	int num;
	cin >> num;
	if (num != -1) {
		root = new TreeNode(num);
		create(root->left);
		create(root->right);
	}
}

void Solution_376::preorderTraversal(TreeNode * root) {
	if (root) {
		cout << root->val << ' ';
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
}

void Solution_376::test() {
	// write your test here

	// input
	TreeNode *root(NULL);
	create(root);

	// algorithm
	int target;
	cin >> target;
	vector<vector<int>> paths;
	paths = binaryTreePathSum(root, target);

	// output
	for (int i = 0; i < paths.size(); i++) {
		for (int j = 0; j < paths[i].size(); j++)
			cout << paths[i][j] << ' ';
		cout << endl;
	}
}