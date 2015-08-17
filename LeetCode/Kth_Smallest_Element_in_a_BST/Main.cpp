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
	int result = -1;
	void rec(TreeNode*root, int &k){
		if (root == NULL){
			return;
		}
		rec(root->left, k);
		if (k != 0){
			k--;
			if (k == 0){
				result = root->val;
				return;
			}
			else{
				rec(root->right, k);
			}
		}
	}
	int kthSmallest(TreeNode* root, int k) {
		rec(root, k);
		return result;
	}
};
int main(){
	return 0;
}