#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode*cl1 = l1;
		ListNode*cl2 = l2;
		ListNode*head = new ListNode(0);
		ListNode*tmp1 = head;
		int carry = 0;
		while (cl1 != NULL&&cl2 != NULL){
			int num = carry + cl1->val + cl2->val;
			carry = num / 10;
			num = num % 10;
			tmp1->next = new ListNode(num);
			tmp1 = tmp1->next;
			cl1 = cl1->next;
			cl2 = cl2->next;
		}
		cl1 = cl1 == NULL ? cl2 : cl1;
		while (cl1 != NULL){
			int num = carry + cl1->val;
			carry = num / 10;
			num = num % 10;
			tmp1->next = new ListNode(num);
			tmp1 = tmp1->next;
			cl1 = cl1->next;
		}
		if (carry != 0) tmp1->next = new ListNode(carry);
		return head->next;
	}
};
int main(){

	return 0;
}