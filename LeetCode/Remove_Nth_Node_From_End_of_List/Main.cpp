#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		if (head == NULL) return head;
		ListNode *tmpH = new ListNode(1);
		tmpH->next = head;
		vector<ListNode*> kl;
		for (ListNode *cur1 = tmpH, *cur = head; cur != NULL; cur1 = cur1->next, cur = cur->next){
			kl.push_back(cur1);
		}
		ListNode *parent = kl[kl.size() - n];
		parent->next = parent->next->next;
		return tmpH->next;
	}
};
int main(){
	return 0;
}