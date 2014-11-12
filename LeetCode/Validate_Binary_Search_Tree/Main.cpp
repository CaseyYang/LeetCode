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
	bool isBST = true;
	bool init = true;
	int pre = 1;
	void function(TreeNode *root){
		if (root->left != NULL){
			function(root->left);
		}
		if (!init&&root->val <= pre){
			isBST = false;
			return;
		}
		pre = root->val;
		init = false;
		if (root->right != NULL){
			function(root->right);
		}
	}
	bool isValidBST(TreeNode *root) {
		if (root == NULL){
			return true;
		}
		else{
			function(root);
			return isBST;
		}
	}
};

int main(){
	return 0;
}