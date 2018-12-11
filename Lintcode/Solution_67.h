#pragma once
#include <vector>
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

class Solution_67 {
public:
	/**
	 * @param root: A Tree
	 * @return: Inorder in ArrayList which contains node values.
	 */
	vector<int> inorderTraversal(TreeNode * root);
	void inorderTraversal(TreeNode *root, vector<int> &nodes);
	void create(TreeNode *&node);
	void test();
};