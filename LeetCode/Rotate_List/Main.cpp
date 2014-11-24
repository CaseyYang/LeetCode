#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode *rotateRight(ListNode *head, int k) {
		if (head == NULL || head->next == NULL) return head;
		ListNode *tmpHead = new ListNode(0);
		tmpHead->next = head;
		ListNode *cur = head;
		int count = 0;
		while (cur != NULL){
			cur = cur->next;
			++count;
		}
		k = k%count;
		if (k == 0 || k == count) return head;
		cout << count << endl;
		cur = tmpHead;
		int curIndex = 0;
		for (; curIndex < count - k; ++curIndex){
			cur = cur->next;
		}
		tmpHead->next = cur->next;
		ListNode *tmp2 = cur->next;
		cur->next = NULL;
		while (tmp2->next != NULL) tmp2 = tmp2->next;
		tmp2->next = head;
		return tmpHead->next;
	}
};
int main(){
	ListNode *l1 = new ListNode(1);
	ListNode *l2 = new ListNode(2);
	l1->next = l2;
	Solution s;
	ListNode *kl1=s.rotateRight(l1,1);
	while (kl1 != NULL){
		cout << kl1->val << endl;
		kl1 = kl1->next;
	}
}