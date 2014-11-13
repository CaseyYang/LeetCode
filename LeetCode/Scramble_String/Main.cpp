#include<iostream>
using namespace std;
class Solution {
public:
	bool isScramble(string s1, string s2) {
		//first count the characters
		if (s1 == s2) return true;
		if (s1.size() != s2.size()) return false;
		int charset[26] = { 0 };
		//for (int i = 0; i < s1.size(); ++i)			charset[s1[i] - 'a']++;
		//for (int i = 0; i < s2.size(); ++i)			charset[s2[i] - 'a']--;
		//for (int i = 0; i < 26; ++i)			if (charset[i] != 0) return false;
		//end

		bool result = false;
		for (int i = 1; i < s1.size(); ++i) {
			result = isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i));
			if (result) return true;
			result = isScramble(s1.substr(0, i), s2.substr(s1.size() - i, i)) && isScramble(s1.substr(i), s2.substr(0, s1.size() - i));
			if (result) return true;
		}
		return false;
	}
};
int main(){
	return 0;
}