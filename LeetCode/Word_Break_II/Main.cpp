#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

//解法来源：http://blog.csdn.net/lanxu_yy/article/details/17310247
//勘误：“dp[i][j]表示，从i到j的字符串是否在字典之中。”-->dp[i][j]表示的是从第i个字符起始j个字符的子串是否在字典中

//我的思路
//构造一个多叉树结构：根结点是""，第一层叶子结点是从第一个字符开始的在字典中的字符（即cat和cats），第二层分别为sand和and，即每层是从父结点末尾开始所找到的在字典中存在的单词
//最后深度遍历树结构，遇到叶子结点时输出从所有父结点和叶子结点即可

class Solution {
public:
	vector<bool>* dp;
	vector<string> mystring;
	vector<string> result;
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
			system("pause");
		}
		else
		{
			/////////////////////////////////////////////这部分很难理解：从dp[0][9]~dp[9][0]检查，若dp[i][j]为true，则保存字符串进mystrings，然后从dp[0][i-1]再找（因为前后字符串不可能重叠，所以最长不可能超过i）
			for (int k = 0; k <= i; k++)
			{
				cout << "k=" << k << ", i=" << i << ", i-k=" << i - k << endl;
				if (dp[k][i - k])
				{
					mystring.push_back(s.substr(k, i - k + 1));
					cout << "k=" << k << ", i=" << i << ", " << mystring.back() << endl;
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
	unordered_set<string> dict = unordered_set<string>();
	dict.insert("cat");
	dict.insert("cats");
	dict.insert("and");
	dict.insert("sand");
	dict.insert("dog");
	string ss = "catsanddog";
	Solution s;
	s.wordBreak(ss, dict);
	return 0;
}