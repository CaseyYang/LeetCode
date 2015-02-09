#include<iostream>
#include<stack>
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
using namespace std;
class BSTIterator {
public:
	stack<TreeNode*> s;
	BSTIterator(TreeNode *root) {
		TreeNode *cur = root;
		while (cur){
			s.push(cur);
			cur = cur->left;
		}
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !s.empty();
	}

	/** @return the next smallest number */
	int next() {
		TreeNode *cur = s.top();
		s.pop();
		TreeNode *right = cur->right;
		while (right){
			s.push(right);
			right = right->left;
		}
		return cur->val;
	}
};
int main(){
	return 0;
}