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

			}
		while ()
		}
	}
};

int main(){
	return 0;
}