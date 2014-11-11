#include<iostream>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	void function1(TreeLinkNode *left, TreeLinkNode *right){
		int leftUpdated = true;
		int rightUpdated = true;
		while (left != NULL&&right != NULL&&leftUpdated&&rightUpdated){
			if (left->next == NULL) {
				left->next = right;
				if (left->right != NULL){
					left = left->right;
				}
				else{
					if (left->left != NULL){
						left = left->left;
					}
					else{
						leftUpdated = false;
					}
				}
				if (right->left != NULL){
					right = right->left;
				}
				else{
					if (right->right != NULL){
						right = right->right;
					}
					else{
						rightUpdated = false;
					}
				}
			}
			else{
				break;
			}
		}
	}
	void DFS(TreeLinkNode *root){
		if (root->left != NULL&&root->right != NULL){
			function1(root->left, root->right);
		}
		if (root->left != NULL){
			DFS(root->left);
		}
		if (root->right != NULL){
			DFS(root->right);
		}
	}
	void connect(TreeLinkNode *root) {
		if (root == NULL){
			return;
		}
		else{
			DFS(root);
		}
	}
};

int main(){
	return 0;
}