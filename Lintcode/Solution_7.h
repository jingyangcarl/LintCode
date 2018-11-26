#pragma once
#include <sstream>
#include <string>
#include <vector>
using namespace std;

//Definition of TreeNode:
class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};

class Solution_7 {
public:
	/**
	* This method will be invoked first, you should design your own algorithm
	* to serialize a binary tree which denote by a root node to a string which
	* can be easily deserialized by your own "deserialize" method later.
	*/
	string serializeDFS(TreeNode *root);

	/**
	* This method will be invoked second, the argument data is what exactly
	* you serialized at method "serialize", that means the data is not given by
	* system, it's given by your own serialize method. So the format of data is
	* designed by yourself, and deserialize it here as you serialize it in
	* "serialize" method.
	*/
	TreeNode * deserializeDFS(string &data);

	// Carl: create a tree
	void createTree(TreeNode *&root);

private:
	void serializeDFS(TreeNode *root, ostringstream &out);
	TreeNode* deserializeDFS(istringstream &in);
};
