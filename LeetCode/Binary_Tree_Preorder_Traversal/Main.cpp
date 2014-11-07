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
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> result = vector<int>();
		if (root != NULL){
			stack<TreeNode*> tStack = stack<TreeNode*>();
			tStack.push(root);
			while (!tStack.empty()){
				TreeNode *cur = tStack.top();
				result.push_back(cur->val);
				tStack.pop();
				if (cur->right != NULL){
					tStack.push(cur->right);
				}
				if (cur->left != NULL){
					tStack.push(cur->left);
				}
			}
		}
		return result;
	}
};

int main(){
	return 0;
}