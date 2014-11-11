#include<iostream>
#include<queue>
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
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int>> results = vector<vector<int>>();
		if (root == NULL) return results;
		TreeNode *tag = new TreeNode(1);
		queue<TreeNode*> tq = queue<TreeNode*>();
		tq.push(root);
		tq.push(tag);
		results.push_back(vector<int>());
		while (true){
			TreeNode *cur = tq.front();
			tq.pop();
			if (cur == tag){
				if (tq.empty()){
					break;
				}
				else{
					tq.push(cur);
					results.push_back(vector<int>());
					continue;
				}
			}
			else{
				results.back().push_back(cur->val);
				if (cur->left != NULL){
					tq.push(cur->left);
				}
				if (cur->right != NULL){
					tq.push(cur->right);
				}
			}
		}
		for (int i = 1; i < results.size(); i = i + 2){
			reverse(results[i].begin(), results[i].end());
		}
		return results;
	}
};

int main(){

	return 0;
}