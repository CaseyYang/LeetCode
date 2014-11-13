#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		if (s.size() == 0 || s.size() == 1 && s[0] != '0'){
			return s.size();
		}
		else{
			vector<int> dp = vector<int>(s.size() + 1);
			dp[0] = 1;
			if (s[0] != '0'){
				dp[1] = 1;
			}
			else{
				return 0;
			}
			int preInt = s[0] - '0';
			for (int i = 2; i <= s.size(); ++i){
				dp[i] = 0;
				int curNum = s[i - 1] - '0';
				int biggerNum = preInt * 10 + curNum;
				if (curNum != 0){
					dp[i] = dp[i - 1];
					if (biggerNum != curNum&&biggerNum <= 26){
						dp[i] += dp[i - 2];
					}
				}
				else{
					if (biggerNum != curNum&&biggerNum <= 26){
						dp[i] += dp[i - 2];
					}
					else{
						return 0;
					}
				}
				preInt = curNum;
			}
			return dp[s.size()];
		}
	}
};

int main(){
	return 0;
}