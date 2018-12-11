#include "Solution_68.h"

vector<int> Solution_68::postorderTraversal(TreeNode * root) {
	// write your code here
	vector<int> nodes;
	postorderTraversal(root, nodes);
	return nodes;
}

vector<int> Solution_68::postorderTraversal_2(TreeNode * root) {
	// write your code here

	vector<int> nodes;
	stack<TreeNode> nodeStack;
	if (root) nodeStack.push(*root);
	else return nodes;

	while (!nodeStack.empty()) {
		TreeNode currentNode = nodeStack.top();
		if (!currentNode.left && !currentNode.right)
			nodes.push_back(currentNode.val);
		nodeStack.pop();
		if (currentNode.right || currentNode.left) nodeStack.push(TreeNode(currentNode.val));
		if (currentNode.right) nodeStack.push(*currentNode.right);
		if (currentNode.left) nodeStack.push(*currentNode.left);
	}
	return nodes;
}

void Solution_68::postorderTraversal(TreeNode * root, vector<int>& nodes) {
	// write your code here
	if (root) {
		postorderTraversal(root->left, nodes);
		postorderTraversal(root->right, nodes);
		nodes.push_back(root->val);
	}
	else return;
}

void Solution_68::create(TreeNode *& node) {
	int n;
	cin >> n;
	if (n != -1) {
		node = new TreeNode(n);
		create(node->left);
		create(node->right);
	}
	else return;
}

void Solution_68::test() {
	// write your test here

	// input
	TreeNode *tree = NULL;
	create(tree);

	// algorithm
	vector<int> nodes;
	nodes = postorderTraversal_2(tree);

	// output
	vector<int>::iterator iter;
	for (iter = nodes.begin(); iter != nodes.end(); iter++)
		cout << *iter << " ";
}
