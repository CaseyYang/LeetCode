#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int longestValidParentheses(string s) {
		vector<bool> isValids;
		stack<int> st;
		for (int i = 0; i < s.size(); ++i){
			if (s[i] == '('){
				st.push(i);
				isValids.push_back(false);
			}
			else{
				if (!st.empty() && s[st.top()] != s[i]){
					isValids[st.top()] = true;
					st.pop();
					isValids.push_back(true);
				}
				else{
					isValids.push_back(false);
					if(!st.empty()) st.pop();
				}
			}
		}
		int maxLength = 0;
		int length = 0;
		for (int i = 0; i < isValids.size(); ++i){
			if (isValids[i]){
				++length;
				maxLength = max(maxLength, length);
			}
			else{
				length = 0;
			}
		}
		return maxLength;
	}
};
int main(){
	return 0;
}