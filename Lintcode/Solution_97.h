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

class Solution_97 {
public:
	/**
	 * @param root: The root of binary tree.
	 * @return: An integer
	 */
	int maxDepth(TreeNode * root);
};