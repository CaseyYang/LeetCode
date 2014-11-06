#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
	int evalRPN(vector<string> &tokens) {
		stack<int> tokensStack = stack<int>();
		for (int i = 0; i < tokens.size(); ++i){
			if (tokens[i] == "+"){
				int n1 = tokensStack.top();
				tokensStack.pop();
				int n2 = tokensStack.top();
				tokensStack.pop();
				int tmpResult = n1 + n2;
				tokensStack.push(tmpResult);
				continue;
			}
			if (tokens[i] == "-"){
				int n1 = tokensStack.top();
				tokensStack.pop();
				int n2 = tokensStack.top();
				tokensStack.pop();
				int tmpResult = n2 - n1;
				tokensStack.push(tmpResult);
				continue;
			}
			if (tokens[i] == "*"){
				int n1 = tokensStack.top();
				tokensStack.pop();
				int n2 = tokensStack.top();
				tokensStack.pop();
				int tmpResult = n1 * n2;
				tokensStack.push(tmpResult);
				continue;
			}
			if (tokens[i] == "/"){
				int n1 = tokensStack.top();
				tokensStack.pop();
				int n2 = tokensStack.top();
				tokensStack.pop();
				int tmpResult = n2 / n1;
				tokensStack.push(tmpResult);
				continue;
			}
			tokensStack.push(atoi(tokens[i].c_str()));
		}
		return tokensStack.top();
	}
};

int main(){
	string expression1[] = { "2", "1", "+", "3", "*" };
	string expression2[] = { "4", "13", "5", "/", "+" };
	vector<string> expressionV = vector<string>(expression2, expression2 + 5);
	Solution s;
	cout << s.evalRPN(expressionV) << endl;
	return 0;
}