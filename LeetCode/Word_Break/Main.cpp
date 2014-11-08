#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
	vector<bool> *dp;
	//checkFromLast和checkFromFirst都有各自的缺陷，在不同样例下可能会超时，具体见main函数
	bool checkFromLast(unordered_set<string> &dict, string s, int endLength){//和word break类似，这其实是从最后一个单词开始找的办法
		if (endLength == -1){
			return true;
		}
		else{
			for (int i = 0; i <= endLength; ++i){
				if (dp[i][endLength - i]){
					if (checkFromLast(dict, s, i - 1)){
						return true;
					}
				}
			}
			return false;
		}
	}
	bool checkFromFirst(unordered_set<string> &dict, string s, int startLength){//这是从第一个单词开始找的办法
		if (startLength == s.size()){
			return true;
		}
		else{
			for (int i = 0; i < s.size() - startLength; ++i){
				if (dp[startLength][i]){
					if (checkFromFirst(dict, s, startLength + i + 1)){
						return true;
					}
				}
			}
			return false;
		}
	}
	bool wordBreak2(string s, unordered_set<string> &dict) {//类似Word Break的解法
		dp = new vector<bool>[s.size()];
		for (int i = 0; i < s.size(); ++i){
			for (int j = i; j < s.size(); ++j){
				dp[i].push_back(dict.find(s.substr(i, j - i + 1)) != dict.end());
				//cout << "i=" << i << ", " << j - i << ", " << dp[i].back() << " ";
			}
			//cout << endl;
		}
		//return checkFromLast(dict, s, s.size() - 1);
		return checkFromFirst(dict, s, 0);
	}
	bool wordBreak(string s, unordered_set<string> &dict){
		auto valids = vector<bool>();
		valids.push_back(true);
		for (int i = 1; i <= s.size(); ++i){
			valids.push_back(false);
			for (int j = 0; j < i; ++j){
				valids[i] = valids[i] || (valids[j] && (dict.find(s.substr(j, i - j)) != dict.end()));
			}
		}
		return valids.back();
	}
};

//class Solution {
//public:
//	bool wordBreak(string s, unordered_set<string> &dict) {
//		bool* dp = new bool[s.size() + 1];
//		for (int i = 0; i <= s.size(); i++){
//			dp[i] = false;
//		}
//
//		dp[0] = true;
//		for (int i = 1; i <= s.size(); i++){
//			for (int j = 0; j < i; j++){
//				dp[i] = dp[i] | (dp[j] && (dict.find(s.substr(j, i - j)) != dict.end()));
//			}
//		}
//
//		return dp[s.size()];
//	}
//
//	bool isWord(string s, unordered_set<string> &dict){
//		unordered_set<string>::const_iterator itr = dict.find(s);
//		if (itr != dict.end()){
//			return true;
//		}
//		return false;
//	}
//};


int main(){
	//该样例使用checkFromLast会超时
	//string ss = "baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	//string dictStrs[] = { "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa" };
	//该样例使用checkFromFirst会超时
	//string ss = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
	//string dictStrs[] = { "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa" };
	string ss = "dogs";
	string dictStrs[] = { "dog", "s", "gs" };
	unordered_set<string> dict = unordered_set<string>();
	for (int i = 0; i < 3; ++i){
		dict.insert(dictStrs[i]);
	}
	Solution s;
	cout << s.wordBreak(ss, dict) << endl;
	return 0;
}