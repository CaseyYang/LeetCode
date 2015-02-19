#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode *partition(ListNode *head, int x) {
		if (head == NULL || head->next == NULL) return head;
		ListNode *l1Head = NULL;
		ListNode *l1Cur = NULL;
		ListNode *l2Head = NULL;
		ListNode *l2Cur = NULL;
		ListNode *cur = head;
		while (cur != NULL){
			if (cur->val < x){
				if (l1Head == NULL) {
					l1Head = cur;
					l1Cur = cur;
				}
				else{
					l1Cur->next = cur;
					l1Cur = l1Cur->next;
				}
			}
			else{
				if (l2Head == NULL){
					l2Head = cur;
					l2Cur = cur;
				}
				else{
					l2Cur->next = cur;
					l2Cur = l2Cur->next;
				}
			}
			cur = cur->next;
		}
		if (l2Head != NULL) l2Cur->next = NULL;
		if (l1Head == NULL) return l2Head;
		l1Cur->next = l2Head;
		return l1Head;
	}
};
int main(){
	ListNode *l1 = new ListNode(1);
	ListNode *l2 = new ListNode(2);
	l1->next = l2;
	Solution s;
	s.partition(l1, 0);
}