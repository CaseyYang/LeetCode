#include<iostream>
#include<string>
#include<map>
using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		map<char, int> m = map<char, int>();
		for (int i = 0; i < s.size(); ++i){
			m[s[i]]++;
		}
		if (s.length() != t.length()) return false;
		for (int j = 0; j < t.size(); ++j){
			if (m.find(t[j]) != m.end() && m[t[j]] > 0){
				m[t[j]]--;
			}
			else{
				return false;
			}
		}
		for (auto iter = m.begin(); iter != m.end(); ++iter){
			auto pair = *iter;
			if (pair.second != 0) return false;
		}
		return true;
	}
};