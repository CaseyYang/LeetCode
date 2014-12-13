#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode *reverseKGroup(ListNode *head, int k) {
		if (head == NULL) return head;
		if (k == 1) return head;
		ListNode *tmpH = new ListNode(1);
		tmpH->next = head;
		int count = 1;
		ListNode *cur = head;
		ListNode *parent = tmpH;
		do{			
			if (count > 0 && count % k == 0){
				ListNode *last = cur;//指向要翻转的链表段中最后一个元素
				ListNode *end = cur->next;//指向要翻转的元素准备指向的元素
				ListNode *tmp = parent->next;//指向当前要翻转的元素
				bool first = true;//标记第一次翻转，用以确定cur
				while (last != tmp){//当前要翻转的元素是要翻转的链表段中最后一个元素时说明翻转完毕
					parent->next = tmp->next;
					last->next = tmp;
					tmp->next = end;
					end = tmp;
					tmp = parent->next;
					if (first){
						cur = end;
						first = false;
					}
				}
				parent = cur;
				count = 0;
			}
			cur = cur->next;
			++count;
		} while (cur != NULL);
		return tmpH->next;
	}
	ListNode *swapPairs(ListNode *head) {
		return reverseKGroup(head, 2);
	}
};
int main(){
	ListNode *ss = new ListNode(1);
	Solution s;
	s.reverseKGroup(ss, 2);
	return 0;
}