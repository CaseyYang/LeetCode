#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string str) {
		str = str + " ";
		int start = 0;
		vector<string> words = vector<string>();
		for (int i = 0; i < str.size(); ++i) {
			if (str[i] == ' ') {
				words.push_back(str.substr(start, i - start));
				start = i + 1;
			}
		}
		map<char, string> m = map<char, string>();
		map<string, int> m2 = map<string, int>();
		if (pattern.size() != words.size()) return false;
		for (int i = 0; i < min(pattern.size(), words.size()); ++i) {
			if (m[pattern[i]] == "") {
				if (m2[words[i]] == 0) {
					m[pattern[i]] = words[i];
					m2[words[i]] = pattern[i];
					continue;
				}
				else {
					return false;
				}
			}
			if (m[pattern[i]] != words[i]|| m2[words[i]] != pattern[i]) return false;
		}
		return true;
	}
};

void main() {
	Solution s;
	s.wordPattern("abba", "dog dog dog dog");
}