#include "Solution_85.h"

TreeNode * Solution_85::insertNode(TreeNode * root, TreeNode * node) {
	// write your code here

	// Carl: 
	// Idea: 
	// recursion
	insertNode(root, node->val);
	return root;
}

TreeNode * Solution_85::insertNode_2(TreeNode * root, TreeNode * node) {
	// write your code here

	// Carl: 
	// Idea: 
	// non recursion


	return nullptr;
}

void Solution_85::insertNode(TreeNode * &root, int node) {
	// write your code here

	if (root) {
		if (node < root->val) insertNode(root->left, node);
		else if (node > root->val) insertNode(root->right, node);
		else;
	}
	else root = new TreeNode(node);
}

void Solution_85::create(TreeNode *& node) {
	int n;
	cin >> n;
	if (n != -1) {
		node = new TreeNode(n);
		create(node->left);
		create(node->right);
	}
	else return;
}

void Solution_85::inorderTraversal(TreeNode * root) {
	// write your code here
	if (root) {
		inorderTraversal(root->left);
		cout << root->val << ' ';
		inorderTraversal(root->right);
	}
	else return;
}

void Solution_85::inorderTraversal_2(TreeNode * root) {
	// write your code here
	stack<TreeNode> nodeStack;
	nodeStack.push(*root);
	while (!nodeStack.empty()) {
		TreeNode currentNode = nodeStack.top();
		if (!currentNode.left && !currentNode.right) cout << currentNode.val << " ";
		nodeStack.pop();
		if (currentNode.right) nodeStack.push(*currentNode.right);
		if (currentNode.right || currentNode.left) nodeStack.push(TreeNode(currentNode.val));
		if (currentNode.left) nodeStack.push(*currentNode.left);
	}
}

void Solution_85::test() {
	// write your test here

	// input
	TreeNode *tree = NULL;
	create(tree);
	int n;
	cin >> n;
	TreeNode *node = new TreeNode(n);

	// algorithm
	insertNode(tree, node);

	// output
	inorderTraversal_2(tree);
}


