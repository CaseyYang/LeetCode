#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int curMax;
	int DFS(TreeNode *root){
		int leftMax = -10000;
		int rightMax = -10000;
		if (root->left != NULL){
			leftMax = DFS(root->left);
		}
		if (root->right != NULL){
			rightMax = DFS(root->right);
		}
		if (leftMax + rightMax + root->val > curMax){
			curMax = leftMax + rightMax + root->val;
		}
		if (leftMax + root->val > curMax){
			curMax = leftMax + root->val;
		}
		if (rightMax + root->val > curMax){
			curMax = rightMax + root->val;
		}
		if (root->val > curMax){
			curMax = root->val;
		}
		return max(root->val, max(root->val + leftMax, root->val + rightMax));
	}

	int maxPathSum(TreeNode *root) {
		curMax = -100000;
		if (root == NULL){
			return curMax;
		}
		else
		{
			DFS(root);
			return curMax;
		}
	}
};

int main(){
	return 0;
}