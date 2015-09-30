#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* reverseList(ListNode* start){
		ListNode* last = start;
		ListNode* now = start->next;
		if (now == NULL) return start;
		ListNode* next = start->next->next;
		last->next = NULL;
		while (next != NULL){
			ListNode* tmp = next->next;
			now->next = last;
			last = now;
			now = next;
			next = tmp;
		}
		now->next = last;
		return now;
	}
	bool isPalindrome(ListNode* head) {
		int count = 0;
		ListNode* now = head;
		while (now != NULL){
			++count;
			now = now->next;
		}
		if (count <=1) return true;
		if (count == 2) return head->val == head->next->val;
		if (count == 3) return head->val == head->next->next->val;
		ListNode* start = NULL;
		if (count % 2 == 0){
			int c1 = 0;
			now = head;
			while (now != NULL){
				++c1;
				if (c1 == count / 2){
					start = now->next;
					now->next = NULL;
					break;
				}
				now = now->next;
			}
		}
		else{
			int c2 = 0;
			now = head;
			while (now != NULL){
				++c2;
				if (c2 == count / 2 + 1){
					start = now->next;
					now->next = NULL;
					break;
				}
				now = now->next;
			}
		}
		ListNode* newStart = reverseList(start);
		ListNode* tmp2 = newStart;
		ListNode* tmp1 = head;
		while (tmp2 != NULL){
			if (tmp1->val != tmp2->val) return false;
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
		return true;
	}
};