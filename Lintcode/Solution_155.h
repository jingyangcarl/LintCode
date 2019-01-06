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

class Solution_155 {
public:
	/**
	 * @param root: The root of binary tree
	 * @return: An integer
	 */
	int minDepth(TreeNode * root);
	int minDepth_2(TreeNode * root);
	void minDepth(TreeNode * root, int currDep, int &minDep);
	void create(TreeNode * &root);
	void test();
};