#include "Solution_7.h"
#include <iostream>
#include <stack>

string Solution_7::serializeDFS(TreeNode * root) {

	ostringstream out;
	serializeDFS(root, out);
	return out.str();
}

TreeNode * Solution_7::deserializeDFS(string & data) {

	istringstream in(data);
	return deserializeDFS(in);
	
}

void Solution_7::createTree(TreeNode *&root) {

	string key;
	cin >> key;

	if (key == "#") root == nullptr;
	else {
		root = new TreeNode(stoi(key));
		createTree(root->left);
		createTree(root->right);
	}
}

void Solution_7::serializeDFS(TreeNode * root, ostringstream & out) {
	if (root) {
		out << root->val << " ";
		serializeDFS(root->left, out);
		serializeDFS(root->right, out);
	}
	else out << "# ";
}

TreeNode * Solution_7::deserializeDFS(istringstream & in) {

	string val;
	in >> val;
	if (val == "#") return nullptr;
	TreeNode *root = new TreeNode(stoi(val));
	root->left = deserializeDFS(in);
	root->right = deserializeDFS(in);
	return root;
}
