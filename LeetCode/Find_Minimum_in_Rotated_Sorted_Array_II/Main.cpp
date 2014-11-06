#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
	int findMin_recursion(vector<int> &num) {
		if (num.size() > 0){
			int start = 0;
			int end = num.size() - 1;
			int middle = 0;
			bool flag = false;
			while (num[start] >= num[end] && start + 1 < end){
				middle = (start + end) / 2;
				if (num[start] < num[middle] || num[start] == num[middle] && num[start]>num[end]){
					start = middle;
				}
				if (num[middle] < num[end] || num[middle] == num[end] && num[start]>num[end]){
					end = middle;
				}
				if (num[middle] == num[start] && num[middle] == num[end]){
					flag = true;
					break;
				}
			}
			if (flag){
				vector<int> v1 = vector<int>(num.begin() + start, num.begin() + middle);
				int a = findMin_recursion(v1);
				vector<int> v2 = vector<int>(num.begin() + middle, num.begin() + end);
				int b = findMin_recursion(v2);
				return a < b ? a : b;
			}
			else{
				return num[end] < num[start] ? num[end] : num[start];
			}
		}
	}

	int findMin_non_recursion(vector<int> &num) {
		if (num.size() > 0){
			stack<int> startStack = stack<int>();
			stack<int> endStack = stack<int>();
			int start = 0;
			int end = num.size() - 1;
			int middle = 0;
			int min = num[0];
			startStack.push(start);
			endStack.push(end);
			while (!startStack.empty()){
				start = startStack.top();
				startStack.pop();
				end = endStack.top();
				endStack.pop();
				bool flag = false;
				while (num[start] >= num[end] && start + 1 < end){
					middle = (start + end) / 2;
					if (num[start] < num[middle] || num[start] == num[middle] && num[start]>num[end]){
						start = middle;
					}
					if (num[middle] < num[end] || num[middle] == num[end] && num[start]>num[end]){
						end = middle;
					}
					if (num[middle] == num[start] && num[middle] == num[end]){
						flag = true;
						startStack.push(start);
						endStack.push(middle);
						startStack.push(middle);
						endStack.push(end);
						break;
					}
				}
				if (!flag){
					int tmpMin = num[start] < num[end] ? num[start] : num[end];
					min = tmpMin < min ? tmpMin : min;
				}
			}
			return min;
		}
	}
};

int main(){
	Solution s;
	int array[] = { 1, 1, 1 };
	vector<int> v = vector<int>(array, array + 3);
	cout << s.findMin_non_recursion(v) << endl;
	return 0;
}