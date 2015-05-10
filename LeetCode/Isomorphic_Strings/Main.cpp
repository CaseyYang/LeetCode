#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {		
		map<char, char> m = map<char, char>();
		for (int i = 0; i < s.length(); ++i){
			if (m.find(s[i]) == m.end()){
				m.insert(make_pair(s[i], t[i]));
			}
			else{
				if (m[s[i]] != t[i]){
					return false;
				}
			}
		}
		m.clear();
		for (int i = 0; i < s.length(); ++i){
			if (m.find(t[i]) == m.end()){
				m.insert(make_pair(t[i], s[i]));
			}
			else{
				if (m[t[i]] != s[i]){
					return false;
				}
			}
		}
		return true;
	}
};

int main(){
	return 0;
}