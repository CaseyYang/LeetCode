#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
	int longestValidParentheses(string s) {
		int maxLength = 0;
		int length = 0;
		int count = 0;
		for (int i = 0; i < s.size(); ++i){
			if (s[i] == '('){
				++count;
			}
			else{
				if (count > 0){
					--count;
					length += 2;
				}
				else{
					maxLength = max(maxLength, length);
					length = 0;
				}
			}
		}
		maxLength = max(maxLength, length);
		return maxLength;
	}
};
int main(){
	return 0;
}