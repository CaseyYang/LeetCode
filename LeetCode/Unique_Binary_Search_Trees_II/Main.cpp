#include<iostream>
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
	vector<TreeNode*> function(int start, int end){
		vector<TreeNode*> results;
		if (start < 1 || start > end){
			results.push_back(NULL);
			return results;
		}
		if (start == end){
			TreeNode *curNode = new TreeNode(start);
			results.push_back(curNode);
			return results;
		}
		else{
			for (int i = start; i <= end; ++i){
				vector<TreeNode*> lefts = function(start, i - 1);
				vector<TreeNode*> rights = function(i + 1, end);
				for (int j = 0; j < lefts.size(); ++j){
					for (int k = 0; k < rights.size(); ++k){
						TreeNode *curNode = new TreeNode(i);
						curNode->left = lefts[j];
						curNode->right = rights[k];
						results.push_back(curNode);
					}
				}
			}
			return results;
		}
	}
	vector<TreeNode *> generateTrees(int n) {
		return function(1, n);
	}
};

int main(){
	return 0;
}