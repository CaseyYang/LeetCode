#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	vector<string> result;
	void rec(TreeNode* root, string tmpResult){
		if (root == NULL) return;
		stringstream ss;
		ss << root->val;
		string tmpStr = ss.str();
		if (tmpResult == "") {
			tmpResult += tmpStr;
		}
		else{
			tmpResult += ("->" + tmpStr);
		}
		if (root->left == NULL && root->right == NULL) {
			if (tmpResult!="") result.push_back(tmpResult);
			return;
		}
		if (root->left != NULL) {
			rec(root->left, tmpResult);
		}
		if (root->right != NULL) {
			rec(root->right, tmpResult);
		}
	}
	vector<string> binaryTreePaths(TreeNode* root) {
		rec(root, "");
		return result;
	}
};