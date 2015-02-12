#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<time.h>
using namespace std;

//解法来源：http://blog.csdn.net/lanxu_yy/article/details/17310247
//勘误：“dp[i][j]表示，从i到j的字符串是否在字典之中。”-->dp[i][j]表示的是从第i个字符起始j个字符的子串是否在字典中


class Solution {
public:	
	vector<string> result;
	//从前向后枚举，样例1超时
	vector<string> tmpResult;
	void func(string &s, int start, unordered_set<string> &dict){
		if (start == s.size()){
			string singleResult = "";
			for (int i = 0; i<tmpResult.size(); ++i){
				singleResult += tmpResult[i] + " ";
			}
			if (singleResult != "") result.push_back(singleResult.substr(0, singleResult.size() - 1));
			return;
		}
		for (int i = start + 1; i <= s.size(); ++i){
			string tmpS = s.substr(start, i - start);
			if (dict.find(tmpS) != dict.end()){
				tmpResult.push_back(tmpS);
				func(s, i, dict);
				tmpResult.pop_back();
			}
		}
		return;
	}
	vector<string> wordBreak2(string s, unordered_set<string> &dict) {
		func(s, 0, dict);
		return result;
	}
	//从后向前枚举，样例2超时
	vector<bool>* dp;
	vector<string> mystring;
	vector<string> wordBreak(string s, unordered_set<string> &dict) {
		dp = new vector<bool>[s.size()];
		for (int i = 0; i < s.size(); i++)
		{
			for (int j = i; j < s.size(); j++)
			{
				dp[i].push_back(isMatch(s.substr(i, j - i + 1), dict));
			}
		}
		output(s.size() - 1, s);
		return result;
	}
	void output(int i, string s)
	{
		if (i == -1)
		{
			string str;
			for (int i = mystring.size() - 1; i >= 0; i--)
			{
				str += mystring[i];
				if (i != 0)
				{
					str.push_back(' ');
				}
			}
			result.push_back(str);
		}
		else
		{
			for (int k = 0; k <= i; k++)
			{
				if (dp[k][i - k])
				{
					mystring.push_back(s.substr(k, i - k + 1));
					output(k - 1, s);
					mystring.pop_back();
				}
			}
		}
	}
	bool isMatch(string str, unordered_set<string> &dict)
	{
		unordered_set<string>::const_iterator got = dict.find(str);
		if (got != dict.end())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

int main(){
	//string ss = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
	//string dictStrs[] = { "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa" };
	string ss = "baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	string dictStrs[] = { "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa" };
	unordered_set<string> dict = unordered_set<string>();
	for (int i = 0; i < 10; ++i){
		dict.insert(dictStrs[i]);
	}
	Solution s;
	s.wordBreak2(ss, dict);
	return 0;
}