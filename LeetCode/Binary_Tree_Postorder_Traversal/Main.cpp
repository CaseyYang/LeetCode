#include<iostream>
#include<stack>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> result = vector<int>();
		if (root == NULL){
			return result;
		}
		else{
		stack<TreeNode*> tStack = stack<TreeNode*>();
		tStack.push(root);
		tStack.push(root->left);
		tStack.push(root->right);
		while ()
		}
	}
};

int main(){
	return 0;
}