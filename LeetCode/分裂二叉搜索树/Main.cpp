#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int value;
	TreeNode* left;
	TreeNode* right;
};

//算法思路：
//和二叉搜索树插入新结点类似，从从根结点开始寻找插入位置。
//如果当前结点比分割值大，则当前结点属于比分割值大的那颗子树（以biggerRoot为根的子树）。把当前结点加入那颗子树上一个节点（用biggerTreeCur记录）的左子树
//如果当前结点比分割值小，则当前结点属于比分割值小的那颗子树（以smallerRoot为根的子树）。把当前结点加入那颗子树上一个节点（用smallerTreeCur记录）的右子树
//具体过程可以使用从根结点开始的二叉搜索树模拟，即可感知为何一定是插入biggerTreeCur的左侧/smallerTreeCur的右侧
vector<TreeNode*> func(TreeNode* root, int n) {
	TreeNode* biggerRoot = NULL;
	TreeNode* biggerTreeCur = NULL;
	TreeNode* smallerRoot = NULL;
	TreeNode* smallerTreeCur = NULL;
	TreeNode* cur = root;
	while (cur != NULL) {
		if (n < cur->value) {
			if (biggerRoot == NULL) {
				biggerRoot = cur;
				biggerTreeCur = cur;
			}
			else {
				biggerTreeCur->left = cur;
				biggerTreeCur = biggerTreeCur->left;
			}
			cur = cur->left;
		}
		else {
			if (smallerRoot == NULL) {
				smallerRoot = cur;
				smallerTreeCur = cur;
			}
			else {
				smallerTreeCur->right = cur;
				smallerTreeCur = smallerTreeCur->right;
			}
			cur = cur->right;
		}
	}
	vector<TreeNode*> result = vector<TreeNode*>();
	result.push_back(biggerRoot);
	result.push_back(smallerRoot);
	return result;
}

int main() {
	return 0;
}