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
	TreeNode *wrong1 = NULL;
	TreeNode *wrong2 = NULL;
	TreeNode *recursion(TreeNode *root, TreeNode *preNode){
		if (root->left == NULL&&root->right == NULL){
			if (preNode != NULL){
				if (preNode->val > root->val){
					if (wrong1 == NULL){
						wrong1 = preNode;
					}
					wrong2 = root;
				}
			}
			return root;
		}
		else{
			TreeNode *curPreNode = preNode;
			TreeNode *returnNode = root;
			if (root->left != NULL){
				curPreNode = recursion(root->left, preNode);
			}
			if (curPreNode != NULL&&curPreNode->val > root->val){
				if (wrong1 == NULL){
					wrong1 = curPreNode;
				}
				wrong2 = root;
			}
			if (root->right != NULL){
				returnNode = recursion(root->right, root);
			}
			return returnNode;
		}

	}
	void recoverTree(TreeNode *root) {
		if (root == NULL){
			return;
		}
		else{
			TreeNode *preNode = NULL;
			recursion(root, preNode);
			if (wrong1 != NULL){
				int tmp = wrong1->val;
				wrong1->val = wrong2->val;
				wrong2->val = tmp;
			}
		}
	}
};

int main(){

}