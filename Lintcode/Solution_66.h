#pragma once
#include <vector>
#include <stack>
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

class Solution_66 {
public:
	/**
	 * @param root: A Tree
	 * @return: Preorder in ArrayList which contains node values.
	 */
	vector<int> preorderTraversal(TreeNode * root);
	vector<int> preorderTraversal_2(TreeNode * root);
	void preorderTraversal(TreeNode * root, vector<int> &nodes);
	void create(TreeNode *&node);
	void test();
};