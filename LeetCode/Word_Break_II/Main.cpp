#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

//�ⷨ��Դ��http://blog.csdn.net/lanxu_yy/article/details/17310247
//���󣺡�dp[i][j]��ʾ����i��j���ַ����Ƿ����ֵ�֮�С���-->dp[i][j]��ʾ���Ǵӵ�i���ַ���ʼj���ַ����Ӵ��Ƿ����ֵ���

//�ҵ�˼·
//����һ��������ṹ���������""����һ��Ҷ�ӽ���Ǵӵ�һ���ַ���ʼ�����ֵ��е��ַ�����cat��cats�����ڶ���ֱ�Ϊsand��and����ÿ���ǴӸ����ĩβ��ʼ���ҵ������ֵ��д��ڵĵ���
//�����ȱ������ṹ������Ҷ�ӽ��ʱ��������и�����Ҷ�ӽ�㼴��

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
			/////////////////////////////////////////////�ⲿ�ֺ�����⣺��dp[0][9]~dp[9][0]��飬��dp[i][j]Ϊtrue���򱣴��ַ�����mystrings��Ȼ���dp[0][i-1]���ң���Ϊǰ���ַ����������ص�������������ܳ���i��
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