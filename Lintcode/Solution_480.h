#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//  Definition of TreeNode:
class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};

class Solution_480 {
public:
	/**
	 * @param root: the root of the binary tree
	 * @return: all root-to-leaf paths
	 */
	vector<string> binaryTreePaths(TreeNode * root);
	void binaryTreePaths(TreeNode * root, string path, vector<string> &paths);
	void create(TreeNode *& root);
	void test();
};