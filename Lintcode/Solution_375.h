#pragma once
#include <iostream>
#include <vector>
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

class Solution_375 {
public:
	/**
	 * @param root: The root of binary tree
	 * @return: root of new tree
	 */
	TreeNode * cloneTree(TreeNode * root);
	TreeNode * cloneTree_2(TreeNode * root);
	void cloneTree(TreeNode * root, TreeNode *& copy);
	void create(TreeNode * &root);
	void preorderTraversal(TreeNode * root);
	void test();
};