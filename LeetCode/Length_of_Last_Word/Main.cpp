#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	int lengthOfLastWord(const char *s) {
		string str(s);
		string result = "";
		int start = 0;
		int length = 0;
		bool flag = false;
		for (int i = 0; i < str.size(); ++i){
			if (str[i] == ' '){
				if (flag){
					length = i - start;
				}
				flag = false;
				start = i + 1;
				continue;
			}
			else{
				if (!flag){
					start = i;
					flag = true;
				}
			}
		}
		if (flag) length = str.size() - start;
		return length;
	}
};
int main(){
	return 0;
}