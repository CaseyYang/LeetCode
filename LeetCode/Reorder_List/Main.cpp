#include<iostream>
#include<stack>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void Output(ListNode* head, ListNode *end = NULL){
	ListNode *tmp = head;
	while (tmp != end){
		cout << tmp->val << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

class Solution {
public:
	void reorderList(ListNode *head) {
		if (head != NULL && head->next != NULL){
			ListNode *jump = head;
			ListNode *middle = head;
			while (jump != NULL&&jump->next != NULL){
				jump = jump->next->next;
				middle = middle->next;
			}
			ListNode *backHalf = middle->next;
			middle->next = NULL;
			stack<ListNode*> s = stack<ListNode*>();
			while (backHalf != NULL){
				s.push(backHalf);
				backHalf = backHalf->next;
			}
			jump = head;
			while (!s.empty()){
				ListNode *tmp = s.top();
				s.pop();
				tmp->next = jump->next;
				jump->next = tmp;
				jump = tmp->next;
			}
		}
	}
};

int main(){
	int l[] = { 1, 2, 3, 4 };
	ListNode *head = new ListNode(l[0]);
	ListNode *next = head;
	for (int i = 1; i < (sizeof(l) / 4); ++i){
		next->next = new ListNode(l[i]);
		next = next->next;
	}
	Solution s;
	s.reorderList(head);
	Output(head);
	return 0;
}