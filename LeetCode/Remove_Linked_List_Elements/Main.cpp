#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		if (head == NULL) return head;
		ListNode *sup = new ListNode(-1);
		sup->next = head;
		ListNode *pre = sup;
		while (head != NULL){
			if (head->val == val){
				pre->next = head->next;
				delete head;
				head = pre->next;
			}
			else{
				head = head->next;
				pre = pre->next;
			}
		}
		return sup->next;
	}
};

int main(){
	return 0;
}