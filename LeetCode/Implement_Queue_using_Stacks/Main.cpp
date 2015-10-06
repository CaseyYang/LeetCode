#include<iostream>
#include<stack>
using namespace std;

class Queue {
public:
	stack<int> s1;
	stack<int> s2;
	// Push element x to the back of queue.
	void push(int x) {
		if (!s1.empty()){
			s1.push(x);
		}
		else{
			s2.push(x);
		}
	}

	// Removes the element from in front of queue.
	void pop(void) {
		if (!s1.empty()){
			while (!s1.empty()){
				int tmp = s1.top();
				s1.pop();
				s2.push(tmp);
			}
			s2.pop();
			while (!s2.empty()){
				int tmp = s2.top();
				s2.pop();
				s1.push(tmp);
			}
		}
		else{
			while (!s2.empty()){
				int tmp = s2.top();
				s2.pop();
				s1.push(tmp);
			}
			s1.pop();
			while (!s1.empty()){
				int tmp = s1.top();
				s1.pop();
				s2.push(tmp);
			}
		}
	}

	// Get the front element.
	int peek(void) {
		int result = -1;
		if (!s1.empty()){
			while (!s1.empty()){
				int tmp = s1.top();
				s1.pop();
				s2.push(tmp);
			}
			result = s2.top();
			while (!s2.empty()){
				int tmp = s2.top();
				s2.pop();
				s1.push(tmp);
			}
		}
		else{
			while (!s2.empty()){
				int tmp = s2.top();
				s2.pop();
				s1.push(tmp);
			}
			result = s1.top();
			while (!s1.empty()){
				int tmp = s1.top();
				s1.pop();
				s2.push(tmp);
			}
		}
		return result;
	}

	// Return whether the queue is empty.
	bool empty(void) {
		return s1.empty() && s2.empty();
	}
};