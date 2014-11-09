#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		int gap = 'A' - 'a';
		string newS;
		for (int i = 0; i < s.size(); ++i){
			if (s[i] >= 'A'&&s[i] <= 'Z' || s[i] >= 'a'&&s[i] <= 'z' || s[i] >= '0'&&s[i] <= '9'){
				newS += s[i];
			}
		}
		stack<int> ws = stack<int>();
		for (int i = 0; i < newS.size(); ++i){
			if (i < newS.size() / 2){
				ws.push(newS[i]);
			}
			else{
				if (i == newS.size() / 2 && newS.size() % 2 == 1){
					continue;
				}
				else{

					if (!ws.empty()){
						int top = ws.top();
						int minus = top - newS[i];
						if (minus == 0 || minus == gap || minus == -gap){
							ws.pop();
						}
						else{
							return false;
						}
					}

				}
			}
		}
		if (ws.empty()){
			return true;
		}
		else{
			return false;
		}
	}
};

int main(){
}