#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool sameOrNot = true;
	void function(TreeNode *left, TreeNode *right){
		if (left->val == right->val){
			if (left->left != NULL&&right->right != NULL){
				function(left->left, right->right);
			}
			else{
				if (left->left != right->right){
					sameOrNot = false;
					return;
				}
			}
			if (left->right != NULL&&right->left != NULL){
				function(left->right, right->left);
			}
			else{
				if (left->right != right->left){
					sameOrNot = false;
					return;
				}
			}
		}
		else{
			sameOrNot = false;
			return;
		}
	}
	bool isSymmetric(TreeNode *root) {
		if (root == NULL){
			return true;
		}
		else{
			if (root->left == root->right){
				return true;
			}
			else{
				if (root->left != NULL&&root->right != NULL){
					function(root->left, root->right);
					return sameOrNot;
				}
				else{
					return false;
				}
			}
		}
	}
};

int main(){
	return 0;
}