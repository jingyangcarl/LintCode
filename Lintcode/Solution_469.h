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

class Solution_469 {
public:
	/**
	 * @param a: the root of binary tree a.
	 * @param b: the root of binary tree b.
	 * @return: true if they are identical, or false.
	 */
	bool isIdentical(TreeNode * a, TreeNode * b);
	void isIdentical(TreeNode * a, TreeNode * b, bool &same);
	void create(TreeNode * &root);
	void preorderTraversal(TreeNode * root);
	void test();
};