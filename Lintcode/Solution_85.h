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

class Solution_85 {
public:
	/*
	 * @param root: The root of the binary search tree.
	 * @param node: insert this node into the binary search tree
	 * @return: The root of the new binary search tree.
	 */
	TreeNode * insertNode(TreeNode * root, TreeNode * node);
	void insertNode(TreeNode * &root, int node);
	void create(TreeNode *&node);
	void inorderTraversal(TreeNode *root);
	void inorderTraversal_2(TreeNode *root);
	void test();
};