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
	TreeNode *recursion(vector<int> &inorder, vector<int>::iterator startIter, vector<int>::iterator endIter, vector<int> &postorder, int &indexOfPostOrder){
		if (indexOfPostOrder < 0||startIter==endIter){ return NULL; }
		if (startIter + 1 == endIter){
			TreeNode *curNode = new TreeNode(postorder[indexOfPostOrder]);
			--indexOfPostOrder;
			return curNode;
		}
		else{
			TreeNode *curNode = new TreeNode(postorder[indexOfPostOrder]);
			vector<int>::iterator curIter = find(inorder.begin(), inorder.end(), curNode->val);
			--indexOfPostOrder;
			if (indexOfPostOrder >= 0){
				vector<int>::iterator nextIter = find(inorder.begin(), inorder.end(), postorder[indexOfPostOrder]);
				if (nextIter > curIter){
					curNode->right = recursion(inorder, curIter + 1, endIter, postorder, indexOfPostOrder);
					curNode->left = recursion(inorder, startIter, curIter, postorder, indexOfPostOrder);
				}
				else{
					curNode->left = recursion(inorder, startIter, curIter, postorder, indexOfPostOrder);
					curNode->right = recursion(inorder, curIter+1, endIter, postorder, indexOfPostOrder);
				}
			}
			return curNode;
		}
	}

	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		if (inorder.size() == 0){
			return NULL;
		}
		else{
			int length = postorder.size() - 1;
			return recursion(inorder, inorder.begin(), inorder.end(), postorder, length);
		}
	}
};

int main(){
	return 0;
}