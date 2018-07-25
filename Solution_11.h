#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = nullptr;
    }
};


class Solution_11 {
public:
	/**
	* @param root: param root: The root of the binary search tree
	* @param k1: An integer
	* @param k2: An integer
	* @return: return: Return all keys that k1<=key<=k2 in ascending order
	*/
	vector<int> searchRange(TreeNode * root, int k1, int k2);
	void searchRange(TreeNode *root, vector<int> &result, int k1, int k2);

	void createTree(TreeNode *&root);
};