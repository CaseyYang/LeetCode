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
	TreeNode*result = NULL;
	bool rec(TreeNode*root, TreeNode*p, TreeNode*q){
		if (root == NULL) return false;
		bool b2 = false;
		bool b1 = rec(root->left, p, q);
		if (root == p || root == q){
			if (b1) b2 = true;
			else b1 = true;
		}
		if (b1&&b2){
			result = root;
			return true;
		}
		b2 = rec(root->right, p, q);
		if (b1&&b2){
			result = root;
			return true;
		}
		return b1||b2;
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		rec(root, p, q);
		return result;
	}
};
int main(){
	return 0;
}