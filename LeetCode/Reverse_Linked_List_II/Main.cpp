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
	ListNode *reverseBetween(ListNode *head, int m, int n) {
		if (head == NULL) return NULL;
		ListNode *superHead = new ListNode(1);
		superHead->next = head;
		stack<ListNode*> ls;
		ListNode *cur = superHead;
		ListNode *pre = superHead;
		ListNode *last = NULL;
		for (int i = 0; cur != NULL; ++i){
			if (i == m - 1){
				pre = cur;
			}
			if (i == n + 1){
				last = cur;
			}
			if (i >= m&&i <= n){
				ls.push(cur);
			}
			cur = cur->next;
		}
		while (!ls.empty()){
			pre->next = ls.top();
			pre = pre->next;
			ls.pop();
		}
		pre->next = last;
		pre = superHead->next;
		delete superHead;
		return pre;
	}
};

int main(){
	return 0;
}