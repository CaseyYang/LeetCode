#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode *reverseKGroup(ListNode *head, int k) {
		if (head == NULL) return head;
		if (k == 1) return head;
		ListNode *tmpH = new ListNode(1);
		tmpH->next = head;
		int count = 1;
		ListNode *cur = head;
		ListNode *parent = tmpH;
		do{			
			if (count > 0 && count % k == 0){
				ListNode *last = cur;//ָ��Ҫ��ת������������һ��Ԫ��
				ListNode *end = cur->next;//ָ��Ҫ��ת��Ԫ��׼��ָ���Ԫ��
				ListNode *tmp = parent->next;//ָ��ǰҪ��ת��Ԫ��
				bool first = true;//��ǵ�һ�η�ת������ȷ��cur
				while (last != tmp){//��ǰҪ��ת��Ԫ����Ҫ��ת������������һ��Ԫ��ʱ˵����ת���
					parent->next = tmp->next;
					last->next = tmp;
					tmp->next = end;
					end = tmp;
					tmp = parent->next;
					if (first){
						cur = end;
						first = false;
					}
				}
				parent = cur;
				count = 0;
			}
			cur = cur->next;
			++count;
		} while (cur != NULL);
		return tmpH->next;
	}
	ListNode *swapPairs(ListNode *head) {
		return reverseKGroup(head, 2);
	}
};
int main(){
	ListNode *ss = new ListNode(1);
	Solution s;
	s.reverseKGroup(ss, 2);
	return 0;
}