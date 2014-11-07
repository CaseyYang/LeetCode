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
			stack<pair<TreeNode*, int>> tStack = stack<pair<TreeNode*, int>>();
			TreeNode *left = root;
			do{
				tStack.push(make_pair(left, 0));
				left = left->left;
			} while (left != NULL);
			while (!tStack.empty()){
				pair<TreeNode*,int> cur = tStack.top();
				tStack.pop();
				if (cur.second == 0 && cur.first->right != NULL){
					++cur.second;
					tStack.push(cur);
					left = cur.first->right;
					do{
						tStack.push(make_pair(left, 0));
						left = left->left;
					} while (left != NULL);
					continue;
				}
				else{
					result.push_back(cur.first->val);
				}
			}
			return result;
		}
	}
};

int main(){
	return 0;
}