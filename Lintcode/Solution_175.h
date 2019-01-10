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

class Solution_175 {
public:
	/**
	 * @param root: a TreeNode, the root of the binary tree
	 * @return: nothing
	 */
	void invertBinaryTree(TreeNode * root);
	void invertBinaryTree_2(TreeNode * root);
	void create(TreeNode * &root);
	void preorderTraversal(TreeNode *root);
	void test();
};