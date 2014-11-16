#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		if (head == NULL || head->next == NULL) return head;
		ListNode *prePtr = head;
		ListNode *cur = head->next;
		bool flag = false;
		while (cur != NULL){
			if (prePtr->val != cur->val){
				if (flag){
					prePtr->next = cur;
					flag = false;
				}
				prePtr = prePtr->next;
			}
			else{
				flag = true;
			}
			cur = cur->next;
		}
		if (flag){
			prePtr->next = cur;
		}
		return head;
	}
};
int main(){
	ListNode *l1 = new ListNode(1);
	ListNode *l2 = new ListNode(1);
	l1->next = l2;
	Solution s;
	s.deleteDuplicates(l1);
	return 0;
}