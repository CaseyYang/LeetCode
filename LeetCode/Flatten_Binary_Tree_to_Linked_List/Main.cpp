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
	TreeNode *DFS(TreeNode *root){
		if (root->left == NULL&&root->right == NULL){
			return root;
		}
		else{
			TreeNode *tmp = NULL;
			if (root->left != NULL){
				tmp = DFS(root->left);
				tmp->right = root->right;
				root->right = root->left;
				root->left = NULL;
				if (tmp->right != NULL){
					return DFS(tmp->right);
				}
				else{
					return tmp;
				}
			}
			else{
				return DFS(root->right);
			}
		}
	}
	void flatten(TreeNode *root) {
		if (root == NULL){
			return;
		}
		else{
			DFS(root);
		}
	}
};

int main(){
	TreeNode *root = new TreeNode(1);
	TreeNode *t1 = new TreeNode(2);
	root->left = t1;
	Solution s;
	s.flatten(root);
	return 0;
}