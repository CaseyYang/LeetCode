#include<iostream>
#include<queue>
using namespace std;

class Stack {
public:
	queue<int> q1;
	queue<int> q2;
	// Push element x onto stack.
	void push(int x) {
		if (!q2.empty()){
			q2.push(x);
		}
		else{
			q1.push(x);
		}
	}

	// Removes the element on top of the stack.
	void pop() {
		if (!q1.empty()){
			while (q1.size()!=1){
				int tmp = q1.front();
				q1.pop();
				q2.push(tmp);
			}
			q1.pop();
		}
		else{
			if (!q2.empty()){
				while (q2.size() != 1){
					int tmp = q2.front();
					q2.pop();
					q1.push(tmp);
				}
				q2.pop();
			}
		}
	}

	// Get the top element.
	int top() {
		int result = 0;
		if (!q1.empty()){
			while (q1.size() != 1){
				int tmp = q1.front();
				q1.pop();
				q2.push(tmp);
			}
			result = q1.front();
			q1.pop();
			q2.push(result);
		}
		else{
			if (!q2.empty()){
				while (q2.size() != 1){
					int tmp = q2.front();
					q2.pop();
					q1.push(tmp);
				}
				result = q2.front();
				q2.pop();
				q1.push(result);
			}
		}
		return result;
	}

	// Return whether the stack is empty.
	bool empty() {
		return q1.empty() && q2.empty();
	}
};