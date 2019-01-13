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

class Solution_177 {
public:
	/*
	 * @param A: an integer array
	 * @return: A tree node
	 */
	TreeNode * sortedArrayToBST(vector<int> &A);
	TreeNode * sortedArrayToBST_2(vector<int> &A);
	TreeNode * sortedArrayToBST_3(vector<int> &A);
	void sortedArrayToBST(TreeNode * &root, vector<int> &A, int totalLayer, int currentLayer);
	void sortedArrayToBST_2(TreeNode * &root, vector<int> A, int left, int right);
	TreeNode * sortedArrayToBST_3(vector<int> A, int left, int right);
	void preorderTraversal(TreeNode * root);
	void test();
};