#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
	bool isValid(string s) {
		stack<char> st;
		for (int i = 0; i < s.size(); ++i){
			if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
				st.push(s[i]);
			}
			else{
				if (!st.empty()){
					switch (s[i]){
					case ')':
						if (st.top() != '(') return false;
						else st.pop();
						break;
					case '}':
						if (st.top() != '{') return false;
						else st.pop();
						break;
					case ']':
						if (st.top() != '[') return false;
						else st.pop();
						break;
					}
				}
				else{
					return false;
				}
			}
		}
		if (st.empty())	return true;
		else return false;
	}
};
int main(){
	string ss = "()[]{}";
	Solution s;
	s.isValid(ss);
	return 0;
}