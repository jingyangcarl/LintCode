#pragma once
#include <iostream>
#include <algorithm>
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

class Solution_93 {
public:
	/**
	 * @param root: The root of binary tree.
	 * @return: True if this Binary tree is Balanced, or false.
	 */
	bool isBalanced(TreeNode * root);
	int depth(TreeNode *root);
	void create(TreeNode *&node);
	void inorderTraversal(TreeNode *root);
	void test();
};