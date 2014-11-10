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
			if(left->next==NULL) left->next = right;
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
	}

	void connect(TreeLinkNode *root) {
		if (root == NULL){
			return;
		}
		else{
			TreeLinkNode *cur = root;
			while (cur != NULL){
				function1(cur->left, cur->right);
				cur = cur->left;
			}
			cur = root;
			while (cur != NULL){
				function1(cur->left, cur->right);
				cur = cur->right;
			}
		}
	}
};

int main(){
	return 0;
}