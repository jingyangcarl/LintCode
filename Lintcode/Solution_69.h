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

class Solution_69 {
public:
	/**
	 * @param root: A Tree
	 * @return: Level order a list of lists of integer
	 */
	vector<vector<int>> levelOrder(TreeNode * root);
	void levelOrder(TreeNode * root, int layer, vector<vector<int>> &nodes);
	void create(TreeNode * &node);
	void test();
};