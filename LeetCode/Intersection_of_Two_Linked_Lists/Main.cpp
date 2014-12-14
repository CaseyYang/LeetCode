#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == NULL || headB == NULL){
			return NULL;
		}
		int lengthA = 0;
		int lengthB = 0;
		ListNode *cur = headA;
		while (cur != NULL){
			++lengthA;
			cur = cur->next;
		}
		cur = headB;
		while (cur != NULL){
			++lengthB;
			cur = cur->next;
		}
		cur = lengthA > lengthB ? headA : headB;
		ListNode *other = cur == headA ? headB : headA;
		int diff = abs(lengthA - lengthB);
		while (diff > 0) {
			--diff;
			cur = cur->next;
		}
		while (other != NULL&&cur != NULL&&other != cur){
			other = other->next;
			cur = cur->next;
		}
		return other;
	}
};
int main(){
	return 0;
}