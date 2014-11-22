#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;
		ListNode *head = new ListNode(0);
		ListNode *cur = head;
		ListNode *l1c = l1, *l2c = l2;
		while (l1c != NULL&&l2c != NULL){
			if (l1c->val <= l2c->val){
				cur->next = new ListNode(l1c->val);
				l1c = l1c->next;
			}
			else{
				cur->next = new ListNode(l2c->val);
				l2c = l2c->next;
			}
			cur = cur->next;
		}
		while (l1c != NULL){
			cur->next = new ListNode(l1c->val);
			cur = cur->next;
			l1c = l1c->next;
		}
		while (l2c != NULL){
			cur->next = new ListNode(l2c->val);
			cur = cur->next;
			l2c = l2c->next;
		}
		return head->next;
	}
};
int main(){
	return 0;
}