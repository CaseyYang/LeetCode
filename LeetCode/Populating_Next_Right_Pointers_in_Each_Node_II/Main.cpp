#include<iostream>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	void BFS(TreeLinkNode *head){
		TreeLinkNode *cur = NULL;
		bool isLeft = false;
		while (head != NULL&&cur == NULL){
			if (head->left != NULL){
				cur = head->left;
				isLeft = true;
				break;
			}
			if (head->right != NULL){
				cur = head->right;
				break;
			}
			head = head->next;
		}
		TreeLinkNode *newHead = NULL;
		if (cur != NULL){
			newHead = cur;
			if (isLeft&&head->right != NULL){
				cur->next = head->right;
				cur = cur->next;
			}
			head = head->next;
			while (head != NULL){
				if (head->left != NULL){
					cur->next = head->left;
					cur = cur->next;
				}
				if (head->right != NULL){
					cur->next = head->right;
					cur = cur->next;
				}
				head = head->next;
			}
			BFS(newHead);
		}
	}

	void connect(TreeLinkNode *root) {
		if (root == NULL){
			return;
		}
		else{
			BFS(root);
		}
	}
};

int main(){
	return 0;
}