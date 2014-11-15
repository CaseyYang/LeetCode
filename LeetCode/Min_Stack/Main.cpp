#include<iostream>
#include<stack>
using namespace std;
class MinStack {
public:
	stack<int> pool;
	stack<int> minPool;
	MinStack(){
		pool = stack<int>();
		minPool = stack<int>();
	}
	void push(int x) {
		pool.push(x);
		if (minPool.empty() || x <= minPool.top()){
			minPool.push(x);
		}
	}
	void pop() {
		if (pool.size() > 0){
			if (pool.top() == minPool.top()){
				minPool.pop();
			}
			pool.pop();			
		}
	}
	int top() {
		if (pool.size() > 0){
			return pool.top();
		}
		return 0;
	}
	int getMin() {
		if (!minPool.empty()){
			return minPool.top();
		}
	}
};
int main(){
	return 0;
}