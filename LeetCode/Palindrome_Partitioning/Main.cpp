#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	void deepSearch(int **dp, vector<vector<string>> &result, vector<string> &oneResult, string s, int start){
		if (start == s.size()){
			vector<string> tmp = vector<string>();
			for (int i = 0; i < oneResult.size(); ++i){
				tmp.push_back(oneResult[i]);
			}
			result.push_back(tmp);
			return;
		}
		else{
			for (int i = start; i < s.size(); ++i){
				if (dp[start][i] == 1){
					oneResult.push_back(s.substr(start, i - start + 1));
					deepSearch(dp, result, oneResult, s, i + 1);
					oneResult.pop_back();
				}
			}
			return;
		}
	}
	vector<vector<string>> partition(string s) {
		vector<vector<string>> result = vector<vector<string>>();
		if (s.size() == 0){
			return result;
		}
		else{
			int **dp = new int*[s.size()];
			for (int i = 0; i < s.size(); ++i){
				dp[i] = new int[s.size()];
				for (int j = 0; j < s.size(); ++j){
					dp[i][j] = 0;
				}
				for (int j = i; j < s.size(); ++j){
					int k = 0;
					while (i + k <= j - k&&s[i + k] == s[j - k]){
						++k;
					}
					if (i + k>(i + j) / 2){
						dp[i][j] = 1;
					}
				}
			}
			vector<string> oneResult = vector<string>();
			deepSearch(dp, result, oneResult, s, 0);
			delete[]dp;
			return result;
		}
	}
};

int main(){
	string ss = "abbab";
	Solution s;
	vector<vector<string>> result = s.partition(ss);
	for (int i = 0; i < result.size(); ++i){
		for (int j = 0; j < result[i].size(); ++j){
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}