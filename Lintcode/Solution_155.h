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
	 * @param root: The root of binary tree
	 * @return: An integer
	 */
	int minDepth(TreeNode * root);
	void create(TreeNode * root);
	void test();
	void test();
};