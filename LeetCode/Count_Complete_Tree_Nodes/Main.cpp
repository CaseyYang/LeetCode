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
	int leftNodeDepth(TreeNode*root){
		if (root == NULL) return 0;
		else return 1 + leftNodeDepth(root->left);
	}
	int rightNodeDepth(TreeNode*root){
		if (root == NULL) return 0;
		else return 1 + rightNodeDepth(root->right);
	}
	int countNodes(TreeNode* root) {
		if (root == NULL) return 0;
		int leftDepth = leftNodeDepth(root->left);
		int rightDepth = rightNodeDepth(root->right);
		if (leftDepth == rightDepth) return pow(2,leftDepth+1) - 1;
		else{
			return countNodes(root->left) + countNodes(root->right) + 1;
		}
	}
};

int main(){

}