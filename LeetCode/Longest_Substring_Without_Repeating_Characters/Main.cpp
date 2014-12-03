#include<iostream>
#include<string>
#include<map>
using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int count = 0;
		int start = 0;
		map<char, int> ss = map<char, int>();
		for (int i = 0; i < s.size(); ++i){
			if (ss.find(s[i]) == ss.end()){
				if (i - start + 1>count) count = i - start + 1;
			}
			else{
				int newStart = ss[s[i]] + 1;
				for (int j = start; j < newStart; ++j){
					ss.erase(s[j]);
				}
				start = newStart;
			}
			ss[s[i]] = i;
		}
		return count;
	}
};
int main(){
	return 0;
}