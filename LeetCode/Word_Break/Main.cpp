#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

//class Solution {
//public:
//	//vector<bool> *dp;
//	bool check(unordered_set<string> &dict, string s, int startLength){
//		if (startLength == s.size()){
//			return true;
//		}
//		else{
//			bool result = false;
//			for (int i = 0; startLength + i < s.size(); ++i){
//				if (dict.find(s.substr(startLength, i + 1)) != dict.end()){
//					if (check(dict, s, startLength + i + 1)){
//						return true;
//					}
//				}
//			}
//			return false;
//		}
//	}
//	bool wordBreak(string s, unordered_set<string> &dict) {
//		//dp = new vector<bool>[s.size()];
//		//for (int i = 0; i < s.size(); ++i){
//		//	for (int j = i; j < s.size(); ++j){
//		//		dp[i].push_back(dict.find(s.substr(i, j - i + 1)) != dict.end());
//		//	}
//		//}
//		return check(dict, s, 0);
//	}
//};

class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		bool* dp = new bool[s.size() + 1];
		for (int i = 0; i <= s.size(); i++){
			dp[i] = false;
		}

		dp[0] = true;
		for (int i = 1; i <= s.size(); i++){
			for (int j = 0; j < i; j++){
				dp[i] = dp[i] | (dp[j] && (dict.find(s.substr(j, i - j)) != dict.end()));
			}
		}

		return dp[s.size()];
	}

	bool isWord(string s, unordered_set<string> &dict){
		unordered_set<string>::const_iterator itr = dict.find(s);
		if (itr != dict.end()){
			return true;
		}
		return false;
	}
};


int main(){
	string ss = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
	string dictStrs[] = { "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa" };
	unordered_set<string> dict = unordered_set<string>();
	for (int i = 0; i < 10; ++i){
		dict.insert(dictStrs[i]);
	}
	Solution s;
	s.wordBreak(ss, dict);
	return 0;
}