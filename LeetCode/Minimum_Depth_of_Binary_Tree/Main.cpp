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
	int maxDepth = 100000;
	void DFS(TreeNode *root, int depth){
		++depth;
		if (root->left == NULL&&root->right == NULL){
			if (depth < maxDepth){
				maxDepth = depth;
			}
		}
		else{
			if (root->left != NULL){
				DFS(root->left, depth);
			}
			if (root->right != NULL){
				DFS(root->right, depth);
			}
		}
	}
	int minDepth(TreeNode *root) {
		if (root == NULL){
			return 0;
		}
		else{
			DFS(root, 0);
		}
		return maxDepth;
	}
};

int main(){
	return 0;
}