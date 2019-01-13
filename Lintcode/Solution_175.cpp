#include "Solution_175.h"

void Solution_175::invertBinaryTree(TreeNode * root) {
	// write your code here
	if (root) {
		invertBinaryTree(root->left);
		invertBinaryTree(root->right);
		
		// swap
		TreeNode * temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
}

void Solution_175::invertBinaryTree_2(TreeNode * root) {
	// write your code here

	// Carl: try non-recursion
	vector<TreeNode *> nodeStack;
	nodeStack.push_back(root);
	while (!nodeStack.empty()) {
		// get current node
		TreeNode *currentNode = nodeStack.back();
		nodeStack.pop_back();
		// swap
		TreeNode *swap;
		swap = (*currentNode).left;
		(*currentNode).left = (*currentNode).right;
		(*currentNode).right = swap;
		// push nodes into the stack;
		if((*currentNode).left) nodeStack.push_back((*currentNode).left);
		if((*currentNode).right) nodeStack.push_back((*currentNode).right);
	}
}

void Solution_175::create(TreeNode *& root) {
	int num;
	cin >> num;
	if (num == -1) root = NULL;
	else {
		root = new TreeNode(num);
		create(root->left);
		create(root->right);
	}
}

void Solution_175::preorderTraversal(TreeNode * root) {
	if (root) {
		cout << root->val << ' ';
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
}

void Solution_175::test() {
	// write your test here

	// input
	TreeNode *root;
	create(root);

	// algorithm;
	invertBinaryTree_2(root);

	// output;
	preorderTraversal(root);
}
