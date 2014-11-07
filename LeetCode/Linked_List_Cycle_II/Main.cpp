#include<iostream>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if (head == NULL || head->next == NULL){
			return NULL;
		}
		else{
			ListNode *fast = head;
			ListNode *slow = head;
			bool hasCircle = false;
			while (fast != NULL&&fast->next != NULL){
				fast = fast->next->next;
				slow = slow->next;
				if (fast == slow){
					hasCircle = true;
					break;
				}
			}
			if (hasCircle){
				//寻找环入口证明：http://blog.csdn.net/wencheng2998/article/details/5935771
				fast = head;
				while (fast != slow){
					fast = fast->next;
					slow = slow->next;
				}
				return fast;
			}
			else{
				return NULL;
			}
		}
	}
};

int main(){
	return 0;
}