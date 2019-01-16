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

class Solution_376 {
public:
	/*
	 * @param root: the root of binary tree
	 * @param target: An integer
	 * @return: all valid paths
	 */
	vector<vector<int>> binaryTreePathSum(TreeNode * root, int target);
	void binaryTreePathSum(TreeNode * root, int target, int current, vector<vector<int>> &paths, vector<int> &currentPath);
	void create(TreeNode *& root);
	void preorderTraversal(TreeNode *root);
	void test();
};