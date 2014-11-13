#include<iostream>
#include<vector>
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
	vector<int> inorderTraversal(TreeNode *root) {
		vector<int> result;
		if (root == NULL) return result;
		stack<TreeNode*> ts;
		TreeNode *cur = root;
		while (cur != NULL) {
			ts.push(cur);
			cur = cur->left;
		}
		while (!ts.empty()){
			TreeNode* p = ts.top();
			ts.pop();
			result.push_back(p->val);
			TreeNode *cur = p->right;
			while (cur != NULL){
				ts.push(cur);
				cur = cur->left;
			}
		}
		return result;
	}
};
int main(){
	return 0;
}