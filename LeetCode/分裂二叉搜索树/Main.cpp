#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int value;
	TreeNode* left;
	TreeNode* right;
};

vector<TreeNode*> func(TreeNode* root,int n) {
	TreeNode* cur = root;
	TreeNode* parent = root;
	while (cur != NULL) {
		if (cur->value > n) {
			parent
			cur = cur->left;
		}
		else {
			cur = cur->right;
		}
	}
}

int main() {
	return 0;
}