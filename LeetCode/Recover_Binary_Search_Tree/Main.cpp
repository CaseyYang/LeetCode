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
	TreeNode *pre = NULL;
	void recursion(TreeNode *cur){
		if (cur == NULL) return;
		recursion(cur->left);
		if (pre != NULL&&pre->val > cur->val){
			if (wrong1 == NULL){
				wrong1 = pre;
			}
			wrong2 = cur;
		}
		pre = cur;
		recursion(cur->right);
	}
	void recoverTree(TreeNode *root) {
		if (root == NULL){
			return;
		}
		else{
			recursion(root);
			swap(wrong1->val, wrong2->val);
			//TreeNode *preNode = NULL;
			//recursion(root, preNode);
			//if (wrong1 != NULL){
			//	int tmp = wrong1->val;
			//	wrong1->val = wrong2->val;
			//	wrong2->val = tmp;
			//}
		}
	}
};

int main(){

}