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
	TreeNode *buildTree(vector<int> &num, int start, int end){
		if (start > end){
			return NULL;
		}
		else{
			int middle = start + (end - start) / 2;
			TreeNode *leftNode = buildTree(num, start, middle - 1);
			TreeNode *newNode = new TreeNode(num[middle]);
			newNode->left = leftNode;
			newNode->right = buildTree(num, middle + 1, end);
			return newNode;
		}
	}
	TreeNode *sortedArrayToBST(vector<int> &num) {
		if (num.size() == 0){
			return NULL;
		}
		else{
			buildTree(num, 0, num.size() - 1);
		}
	}
};

int main(){
	return 0;
}