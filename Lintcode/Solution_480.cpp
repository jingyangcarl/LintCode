#include "Solution_480.h"

vector<string> Solution_480::binaryTreePaths(TreeNode * root) {
	// write your code here
	vector<string> paths;
	if (!root) return paths;
	binaryTreePaths(root, "", paths);
	return paths;
}

void Solution_480::binaryTreePaths(TreeNode * root, string path, vector<string> &paths) {
	// write your code here
	if (root) {
		if (!root->left && !root->right)
			paths.push_back(path + to_string(root->val));
		else {
			binaryTreePaths(root->left, path + to_string(root->val) + "->", paths);
			binaryTreePaths(root->right, path + to_string(root->val) + "->", paths);
		}
	}
}

void Solution_480::create(TreeNode *& root) {
	int num;
	cin >> num;
	if (num != -1) {
		root = new TreeNode(num);
		create(root->left);
		create(root->right);
	}
}

void Solution_480::test() {
	// write your test here

	// input
	TreeNode *root;
	create(root);

	// algorithm
	vector<string> paths = binaryTreePaths(root);

	// output;
	for (int i = 0; i < paths.size(); i++) {
		cout << paths[i] << endl;
	}
}