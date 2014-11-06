#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
	void reverseWords(string &s) {
		stack<string> strStack = stack<string>();
		int start = -1;
		for (int i = 0; i < s.size(); ++i){
			if (s[i] != ' '&&start == -1){
				start = i;
				continue;
			}
			if (s[i] == ' '&&start != -1){
				strStack.push(s.substr(start, i - start));
				start = -1;
			}
		}
		if (start != -1){
			strStack.push(s.substr(start, s.size() - start));
			cout << start << " " << s.size() - start << endl;
		}
		s.clear();
		while (!strStack.empty()){
			if (strStack.size()>1){
				s.append(strStack.top() + " ");
			}
			else{
				s.append(strStack.top());
			}
			strStack.pop();
		}
	}
};

int main(){
	string s = "the sky is blue";
	cout << s.size() << endl;
	cout << s.length() << endl;
	Solution ss;
	ss.reverseWords(s);
	cout << s << "#" << endl;
	return 0;
}