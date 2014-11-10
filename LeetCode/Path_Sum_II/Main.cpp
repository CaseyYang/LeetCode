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
	bool DFS(TreeNode *root, int sum, int curSum){
		if (root->left == NULL&&root->right == NULL){
			if (curSum + root->val == sum){
				return true;
			}
			else{
				return false;
			}
		}
		else{
			int newSum = curSum + root->val;
			bool leftT = false;
			bool rightT = false;
			if (root->left != NULL){
				leftT = DFS(root->left, sum, newSum);
			}
			if (root->right != NULL){
				rightT = DFS(root->right, sum, newSum);
			}
			return leftT || rightT;
		}
	}
	bool hasPathSum(TreeNode *root, int sum) {
		if (root == NULL){
			return false;
		}
		else{
			return DFS(root, sum, 0);
		}
	}
};

int main(){

	return 0;
}