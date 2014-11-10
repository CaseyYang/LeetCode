#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> results;
	void DFS(TreeNode *root, int sum, int curSum, vector<int> &ts){
		if (root->left == NULL&&root->right == NULL){
			if (curSum + root->val == sum){
				ts.push_back(root->val);
				results.push_back(ts);
				ts.pop_back();
				return;
			}
		}
		else{
			ts.push_back(root->val);
			int tmpSum = curSum + root->val;
			if (root->left != NULL){
				DFS(root->left, sum, tmpSum, ts);
			}
			if (root->right != NULL){
				DFS(root->right, sum, tmpSum, ts);
			}
			ts.pop_back();
		}
	}
	vector<vector<int> > pathSum(TreeNode *root, int sum) {
		if (root == NULL){
			return results;
		}
		else{
			vector<int> ts = vector<int>();
			DFS(root, sum, 0, ts);
			return results;
		}
	}
};

int main(){
	return 0;
}