#include<iostream>
#include<stack>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL) return head;
		stack<ListNode*> s = stack<ListNode*>();
		ListNode *cur = head;
		while (cur->next != NULL){
			s.push(cur);
			cur = cur->next;
		}
		ListNode *tail = cur;
		while (!s.empty()){
			ListNode *tmp = s.top();
			s.pop();
			cur->next = tmp;
			cur = cur->next;
		}
		cur->next = NULL;
		return tail;
	}
};
int main(){

	return 0;
}