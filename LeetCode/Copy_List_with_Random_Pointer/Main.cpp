#include<iostream>
using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (head == NULL){
			return NULL;
		}
		RandomListNode *cur = head;
		while (cur != NULL){
			RandomListNode *copyOfCur = new RandomListNode(cur->label);
			copyOfCur->next = cur->next;
			cur->next = copyOfCur;
			cur = cur->next->next;
		}
		cur = head;
		while (cur != NULL){
			if (cur->random != NULL){
				cur->next->random = cur->random->next;
			}
			cur = cur->next->next;
		}
		RandomListNode *newHead = head->next;
		RandomListNode *recoveryOrigin = head;
		cur = head->next;
		while (cur->next != NULL){
			recoveryOrigin->next = recoveryOrigin->next->next;
			recoveryOrigin = recoveryOrigin->next;
			cur->next = cur->next->next;
			cur = cur->next;
		}
		recoveryOrigin->next = NULL;
		return newHead;
	}
};

int main(){
	RandomListNode *l = new RandomListNode(-1);
	cout <<l->next << endl;
	Solution s;
	RandomListNode *newHead = s.copyRandomList(l);
	cout<<newHead->label<<endl;
	cout << newHead->next << endl;	
	cout << newHead->random << endl;
	cout << l->next << endl;
	return 0;
}