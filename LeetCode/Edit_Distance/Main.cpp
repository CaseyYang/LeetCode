#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	int minDistance(string word1, string word2) {
		if (word1.size() == 0 || word2.size() == 0){
			return max(word1.size(), word2.size());
		}
		vector<vector<int>> dp = vector<vector<int>>();
		for (int i = 0; i < word2.size() + 1; ++i){
			dp.push_back(vector<int>(word1.size() + 1));
		}
		dp[0][0] = 0;
		for (int i = 1; i < word2.size() + 1; ++i){
			dp[i][0] = dp[i - 1][0] + 1;
		}
		for (int j = 1; j < word1.size(); ++j){
			dp[0][j] = dp[0][j - 1] + 1;
		}
		for (int i = 1; i < word2.size() + 1; ++i){
			for (int j = 1; j < word1.size() + 1; ++j){
				if (word2[i - 1] == word1[j - 1]){
					dp[i][j] = dp[i - 1][j - 1];
				}
				else{
					dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
				}
			}
		}
		return dp[word2.size()][word1.size()];
	}
};
int main(){
	return 0;
}