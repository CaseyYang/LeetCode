#include<iostream>
using namespace std;

struct TreeNode {
	int value;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* func(TreeNode* root) {
	if (root == NULL) return 0;
	TreeNode* cur = root;
	TreeNode* last = NULL;
	while (cur->right != NULL) {
		last = cur;
		cur = cur->right;
	}
	if (cur->left != NULL) {
		TreeNode* cur2 = cur->left;
		while (cur2->right != NULL) {
			cur2 = cur2->right;
		}
		return cur2;
	}
	if (last != NULL) {
		return last;
	}
	return cur;
}

void main() {

}