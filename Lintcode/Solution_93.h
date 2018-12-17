#pragma once
#include <iostream>
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

class Solution {
public:
	/**
	 * @param root: The root of binary tree.
	 * @return: True if this Binary tree is Balanced, or false.
	 */
	bool isBalanced(TreeNode * root);
	void isBalanced(TreeNode * root, int leftHeight, int rightHeight, bool isBalanced);
	void create(TreeNode *&node);
	void inorderTraversal(TreeNode *root);
	void test();
};