#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s3.size() != s1.size() + s2.size()){
			return false;
		}
		else{
			if (s3 == "") return true;
			if (s1 == "") return s2 == s3;
			if (s2 == "") return s1 == s3;
			bool **dp = new bool*[s1.size() + 1];
			for (int i = 0; i <= s1.size(); ++i){
				dp[i] = new bool[s2.size() + 1];
			}
			dp[0][0] = true;
			for (int i = 1; i <= s1.size(); ++i){
				dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
			}
			for (int j = 1; j <= s2.size(); ++j){
				dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];
			}
			for (int i = 1; i <= s1.size(); ++i){
				for (int j = 1; j <= s2.size(); ++j){
					dp[i][j] = dp[i - 1][j] && s1[i - 1] == s3[i + j - 1] || dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
				}
			}
			return dp[s1.size()][s2.size()];
		}
	}
};

int main(){
	string s1 = "aa", s2 = "ba", s3 = "aaba";
	Solution s;
	cout << s.isInterleave(s1, s2, s3) << endl;
	return 0;
}