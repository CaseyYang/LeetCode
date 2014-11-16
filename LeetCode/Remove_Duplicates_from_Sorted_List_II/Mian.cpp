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
		ListNode *tmpHead = new ListNode(INT_MAX);
		tmpHead->next = head;
		ListNode *prePtr = tmpHead;
		ListNode *cur = head->next;
		int pre = head->val;
		bool flag = false;
		while (cur != NULL){
			if (pre != cur->val){
				if (!flag){
					prePtr = prePtr->next;
				}
				else{
					prePtr->next = cur;
					flag = false;
				}
				pre = cur->val;
			}
			else{
				flag = true;
			}
			cur = cur->next;
		}
		if (flag){
			prePtr->next = cur;
		}
		return tmpHead->next;
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