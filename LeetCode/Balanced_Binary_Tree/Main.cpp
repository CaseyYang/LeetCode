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
	bool isBalancedFlag = true;
	int DFS(TreeNode *root, int depth){
		++depth;
		if (root->left == NULL&&root->right == NULL){
			return depth;
		}
		else{
			int left, right;
			if (root->left != NULL){
				left = DFS(root->left, depth);
			}
			else{
				left = depth;
			}
			if (root->right != NULL){
				right = DFS(root->right, depth);
			}
			else{
				right = depth;
			}
			if (left - right > 1 || left - right < -1){
				isBalancedFlag = false;
			}
			return max(left, right);
		}
	}
	bool isBalanced(TreeNode *root) {
		if (root == NULL){
			return true;
		}
		else{
			DFS(root, 0);
			return isBalancedFlag;
		}
	}
};

int main(){

}