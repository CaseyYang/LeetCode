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
	int maxDepthI = 0;
	void DFS(TreeNode *root,int depth){
		++depth;
		if (root->left == NULL&&root->right == NULL){
			if (depth > maxDepthI){
				maxDepthI = depth;
			}
			return;
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
	int maxDepth(TreeNode *root) {
		if (root == NULL){
			return 0;
		}
		else{
			DFS(root,0);
			return maxDepthI;
		}
	}
};

int main(){
	return 0;
}