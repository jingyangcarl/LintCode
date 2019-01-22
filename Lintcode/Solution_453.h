#pragma once
#include <iostream>
#include <stack>
using namespace std;

// Definition of TreeNode:
class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};

class Solution_453 {
public:
	/**
	 * @param root: a TreeNode, the root of the binary tree
	 * @return: nothing
	 */
	void flatten(TreeNode * root);
	void create(TreeNode * &root);
	void preorderTraversal(TreeNode *root);
	void test();
};