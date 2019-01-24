#pragma once
#include <iostream>
#include <vector>
using namespace std;

// Definition of ParentTreeNode:
class ParentTreeNode {
public:
	int val;
	ParentTreeNode *parent, *left, *right;
};

class Solution_474 {
public:
	/*
	 * @param root: The root of the tree
	 * @param A: node in the tree
	 * @param B: node in the tree
	 * @return: The lowest common ancestor of A and B
	 */
	ParentTreeNode * lowestCommonAncestorII(ParentTreeNode * root, ParentTreeNode * A, ParentTreeNode * B);
	ParentTreeNode * lowestCommonAncestorII_2(ParentTreeNode * root, ParentTreeNode * A, ParentTreeNode * B);
	void create(ParentTreeNode * &root, ParentTreeNode * parent);
	void preorderTraversal(ParentTreeNode * root);
	void preorderFind(ParentTreeNode * root, int val, ParentTreeNode *& node);
	void test();
};