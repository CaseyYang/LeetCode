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
	TreeNode *recursion(vector<int> &preorder, vector<int>::iterator startIter, vector<int>::iterator endIter, vector<int> &inorder, int &index){
		if (startIter == endIter || index >= preorder.size()){
			return NULL;
		}
		else{
			if (startIter + 1 == endIter){
				TreeNode *newNode = new TreeNode(preorder[index]);
				++index;
				return newNode;
			}
			else{
				TreeNode *newNode = new TreeNode(preorder[index]);
				vector<int>::iterator curIter = find(inorder.begin(), inorder.end(), newNode->val);
				++index;
				if (index < preorder.size()){
					vector<int>::iterator nextIter = find(inorder.begin(), inorder.end(), preorder[index]);
					if (nextIter < curIter){
						newNode->left = recursion(preorder, startIter, curIter, inorder, index);
						newNode->right = recursion(preorder, curIter + 1, endIter, inorder, index);
					}
					else{
						newNode->right = recursion(preorder, curIter + 1, endIter, inorder, index);
						newNode->left = recursion(preorder, startIter, curIter, inorder, index);
					}
				}
				return newNode;
			}
		}
	}
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		if (preorder.size() == 0){
			return NULL;
		}
		else{
			int length = 0;
			return recursion(preorder, inorder.begin(), inorder.end(), inorder, length);
		}
	}
};

int main(){
	return 0;
}