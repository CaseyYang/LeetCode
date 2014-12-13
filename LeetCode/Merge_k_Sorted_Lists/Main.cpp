#include<iostream>
#include<deque>
#include<vector>
#include<algorithm>
#include <functional>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	void Print(deque<ListNode*> &v){
		for (int i = 0; i < v.size(); ++i){
			cout << v[i]->val << " ";
		}
		cout << endl;
	}
	void HeapAdjust(deque<ListNode*> &v, int n){
		int smallest = n;
		int size = v.size();
		if (2 * n + 1 < size){
			if (v[smallest]->val > v[2 * n + 1]->val){
				smallest = 2 * n + 1;
			}
		}
		if (2 * n + 2 < size){
			if (v[smallest]->val > v[2 * n + 2]->val){
				smallest = 2 * n + 2;
			}
		}
		if (smallest != n) {
			swap(v[n], v[smallest]);
			HeapAdjust(v, smallest);
		}
	}
	ListNode* Pop(deque<ListNode*> &v){
		ListNode *result = v.front();
		v.pop_front();
		if (v.size() > 0){
			ListNode *tmp = v.back();
			v.pop_back();
			v.push_front(tmp);
			HeapAdjust(v, 0);
		}
		return result;
	}
	void Insert(deque<ListNode*> &v, ListNode *newElement){
		v.push_back(newElement);
		int child = v.size() - 1;
		int parent = (child - 1) / 2;
		while (parent >= 0 && child != 0){
			if (v[parent]->val <= newElement->val) break;
			else{
				v[child] = v[parent];
				child = parent;
				parent = (child - 1) / 2;
			}
		}
		v[child] = newElement;
		return;
	}
	void MakeHeap(deque<ListNode*> &v){
		for (int i = v.size() / 2; i >= 0; --i){
			HeapAdjust(v, i);
		}
	}
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		deque<ListNode*> v;
		for (int i = 0; i < lists.size(); ++i){
			if (lists[i] != NULL) v.push_back(lists[i]);
		}
		MakeHeap(v);
		ListNode *tmpH = new ListNode(1);
		ListNode *cur = tmpH;
		while (!v.empty()){
			cur->next = Pop(v);
			//cout << "After Pop:" << endl;
			//Print(v);
			cur = cur->next;
			if (cur->next != NULL){
				Insert(v, cur->next);
				//cout << "After Insert:" << endl;
				//Print(v);
			}
		}
		return tmpH->next;
	}
};

int main(){
	int a[] = { -8, 2, 4 };
	int b[] = { -9, -9, -9, -9, -8, -5, -3, -2, 1 };
	int c[] = { -9, -7, -5, -3, -3, -1, 0, 3, 4 };
	int d[] = { -9, -7, -6, -4, -2, -1, 3, 4 };
	int e[] = { -10, -3, 0 };
	int f[] = { -9, 0, 4 };
	int g[] = { -8, -8 };
	vector<ListNode*> v;
	bool init = true;
	ListNode *last = NULL;
	for (int i = 0; i < sizeof(a) / 4; ++i){
		ListNode* tmp = new ListNode(a[i]);
		if (init) {
			v.push_back(tmp);
			init = false;
		}
		else{
			last->next = tmp;
		}
		last = tmp;
	}
	init = true;
	for (int i = 0; i < sizeof(b) / 4; ++i){
		ListNode* tmp = new ListNode(b[i]);
		if (init) {
			v.push_back(tmp);
			init = false;
		}
		else{
			last->next = tmp;
		}
		last = tmp;
	}
	init = true;
	for (int i = 0; i < sizeof(c) / 4; ++i){
		ListNode* tmp = new ListNode(c[i]);
		if (init) {
			v.push_back(tmp);
			init = false;
		}
		else{
			last->next = tmp;
		}
		last = tmp;
	}
	init = true;
	for (int i = 0; i < sizeof(d) / 4; ++i){
		ListNode* tmp = new ListNode(d[i]);
		if (init) {
			v.push_back(tmp);
			init = false;
		}
		else{
			last->next = tmp;
		}
		last = tmp;
	}
	init = true;
	for (int i = 0; i < sizeof(e) / 4; ++i){
		ListNode* tmp = new ListNode(e[i]);
		if (init) {
			v.push_back(tmp);
			init = false;
		}
		else{
			last->next = tmp;
		}
		last = tmp;
	}
	init = true;
	for (int i = 0; i < sizeof(f) / 4; ++i){
		ListNode* tmp = new ListNode(f[i]);
		if (init) {
			v.push_back(tmp);
			init = false;
		}
		else{
			last->next = tmp;
		}
		last = tmp;
	}
	init = true;
	for (int i = 0; i < sizeof(g) / 4; ++i){
		ListNode* tmp = new ListNode(g[i]);
		if (init) {
			v.push_back(tmp);
			init = false;
		}
		else{
			last->next = tmp;
		}
		last = tmp;
	}
	init = true;
	Solution s;
	s.mergeKLists(v);
	return 0;
}