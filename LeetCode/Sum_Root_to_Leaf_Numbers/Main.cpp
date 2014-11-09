#include<iostream>
#include<stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int DFS(TreeNode *root, int result){
		result = result * 10 + root->val;
		if (root->left == NULL&&root->right == NULL){			
			return result;
		}
		else{
			int value = 0;
			if (root->left != NULL){
				value += DFS(root->left, result);
			}
			if (root->right != NULL){
				value += DFS(root->right, result);
			}
			return value;
		}
	}
	int sumNumbers(TreeNode *root) {
		if (root == NULL){
			return 0;
		}
		else{
			return DFS(root, 0);
		}
	}
};

int main(){
	return 0;
}