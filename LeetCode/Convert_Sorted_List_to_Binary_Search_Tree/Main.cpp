#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode *buildTreeNode(ListNode *&curNode, int start, int end){
		if (start > end){
			return NULL;
		}
		else{
			int middle = start + (end - start) / 2;
			TreeNode *leftNode = buildTreeNode(curNode, start, middle - 1);
			TreeNode *newNode = new TreeNode(curNode->val);
			newNode->left = leftNode;
			curNode = curNode->next;
			newNode->right = buildTreeNode(curNode, middle + 1, end);
			return newNode;
		}
	}
	TreeNode *sortedListToBST(ListNode *head) {
		if (head == NULL){
			return NULL;
		}
		else{
			int length = 0;
			for (ListNode *cur = head; cur != NULL; cur = cur->next){
				++length;
			}
			buildTreeNode(head, 0, length - 1);
		}
	}
};

int main(){
	return 0;
}