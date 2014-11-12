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
			if (left->left != NULL&&right->left != NULL){
				function(left->left, right->left);
			}
			else{
				if (left->left != right->left){
					sameOrNot = false;
					return;
				}
			}
			if (left->right != NULL&&right->right != NULL){
				function(left->right, right->right);
			}
			else{
				if (left->right != right->right){
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
	bool isSameTree(TreeNode *p, TreeNode *q) {
		if (p == q){
			return true;
		}
		else{
			if (p != NULL&&q != NULL){
				function(p, q);
				return sameOrNot;
			}
			else{
				return false;
			}
		}
	}
};

int main(){
	return 0;
}