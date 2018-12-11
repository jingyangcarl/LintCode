#include "Solution_69.h"

vector<vector<int>> Solution_69::levelOrder(TreeNode * root) {
	// write your code here
	vector<vector<int>> nodes;
	int layer(0);
	levelOrder(root, layer, nodes);
	return nodes;
}

vector<vector<int>> Solution_69::levelOrder_2(TreeNode * root) {
	// write your code here

	// Carl:
	// Idea:
	// non-recursion, using queue

	vector<vector<int>> nodes;
	queue<pair<TreeNode, int>> nodeQueue;
	if (root) nodeQueue.push(pair<TreeNode, int>(*root, 0));
	else return nodes;

	while (!nodeQueue.empty()) {
		TreeNode currentNode = nodeQueue.front().first;
		int currentlayer = nodeQueue.front().second;
		if (nodes.size() <= currentlayer)
			nodes.push_back(vector<int>());
		nodes.at(currentlayer).push_back(currentNode.val);
		nodeQueue.pop();
		if (currentNode.left) nodeQueue.push(pair<TreeNode, int>(*currentNode.left, currentlayer + 1));
		if (currentNode.right) nodeQueue.push(pair<TreeNode, int>(*currentNode.right, currentlayer + 1));
	}

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
	nodes = levelOrder_2(tree);

	// output
	vector<vector<int>>::iterator iter;
	for (iter = nodes.begin(); iter != nodes.end(); iter++) {
		vector<int>::iterator i;
		for (i = (*iter).begin(); i != (*iter).end(); i++)
			cout << *i << " ";
		cout << endl;
	}
}