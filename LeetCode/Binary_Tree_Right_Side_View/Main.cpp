#include<iostream>
#include<vector>
#include<queue>
using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> rightSideView(TreeNode *root) {
		vector<int> result;
		if (root == NULL) return result;
		queue<TreeNode *> q;
		q.push(root);
		q.push(NULL);
		int lastNum;
		while (!q.empty()){
			TreeNode *cur = q.front();
			q.pop();
			if (cur == NULL) {
				result.push_back(lastNum);
				if (q.empty()) return result;
				q.push(NULL);
				continue;
			}
			lastNum = cur->val;			
			if (cur->left != NULL) q.push(cur->left);
			if (cur->right != NULL) q.push(cur->right);
		}
		return result;
	}
};

int main(){
	return 0;
}