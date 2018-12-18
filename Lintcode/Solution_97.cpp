#include "Solution_97.h"

int Solution_97::maxDepth(TreeNode * root) {
	// write your code here
	if (root) return 1 + max(maxDepth(root->left), maxDepth(root->right));
	else return 0;
}
