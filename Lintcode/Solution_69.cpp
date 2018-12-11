#include "Solution_69.h"

vector<vector<int>> Solution_69::levelOrder(TreeNode * root) {
	// write your code here
	vector<vector<int>> nodes;
	int layer(0);
	levelOrder(root, layer, nodes);
	return nodes;
}

void Solution_69::levelOrder(TreeNode * root, int layer, vector<vector<int>>& nodes) {
	// write your code here
	if (root) {
		if (nodes.size() <= layer)
			nodes.push_back(vector<int>());
		nodes.at(layer).push_back(root->val);
		levelOrder(root->left, ++layer, nodes); layer--;
		levelOrder(root->right, ++layer, nodes); layer--;
	}
	else return;
}

void Solution_69::create(TreeNode *& node) {
	// write your code here
	int n;
	cin >> n;
	if (n != -1) {
		node = new TreeNode(n);
		create(node->left);
		create(node->right);
	}
	else return;
}

void Solution_69::test() {
	// write your test here

	// input
	TreeNode *tree = NULL;
	create(tree);

	// algorithm
	vector<vector<int>> nodes;
	nodes = levelOrder(tree);

	// output
	vector<vector<int>>::iterator iter;
	for (iter = nodes.begin(); iter != nodes.end(); iter++) {
		vector<int>::iterator i;
		for (i = (*iter).begin(); i != (*iter).end(); i++)
			cout << *i << " ";
		cout << endl;
	}
}