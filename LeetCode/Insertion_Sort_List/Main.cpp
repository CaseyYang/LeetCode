#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *insertionSortList(ListNode *head) {
		if (head == NULL || head->next == NULL){
			return head;
		}
		else{
			ListNode *preHead = new ListNode(0);
			preHead->next = head;
			ListNode *form = head;
			ListNode *cur = head->next;
			while (cur != NULL){
				ListNode *insertPosition = preHead;
				while (insertPosition->next != cur&&insertPosition->next->val <= cur->val){
					insertPosition = insertPosition->next;
				}
				if (insertPosition->next->val != cur->val){
					ListNode *tmp = cur;
					cur = cur->next;
					form->next = cur;
					tmp->next = insertPosition->next;
					insertPosition->next = tmp;
				}
				else{
					form = cur;
					cur = cur->next;
				}
			}
			form = preHead->next;
			delete preHead;
			return form;
		}
	}
};

void Output(ListNode* head, ListNode *end = NULL){
	ListNode *tmp = head;
	while (tmp != end){
		cout << tmp->val << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

int main(){
	//int l[] = { 1, 3, 3, 1, 3, 1, 3, 3, 2, 3, 2, 2, 1, 1, 1, 3, 2, 2, 1, 1, 2, 2 };
	int l[] = { 4,1, 2, 3, 4 };
	cout << sizeof(l) / 4 << endl;
	ListNode *head = new ListNode(l[0]);
	ListNode *next = head;
	for (int i = 1; i < (sizeof(l) / 4); ++i){
		next->next = new ListNode(l[i]);
		next = next->next;
	}
	Solution s;
	Output(s.insertionSortList(head));

	return 0;
}