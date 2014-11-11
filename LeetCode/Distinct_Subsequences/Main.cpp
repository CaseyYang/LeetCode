#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	int numDistinct(string S, string T) {
		if (S.size() == 0 || T.size() == 0) return 0;
		if (S.size() < T.size()) return 0;
		int **dp = new int*[T.size()];
		for (int i = 0; i < T.size(); ++i){
			dp[i] = new int[S.size()];
			for (int j = i; j < S.size(); ++j){
				if (S[j] == T[i]){
					if (j == i){
						if (i == 0){
							dp[i][j] = 1;
						}
						else{
							dp[i][j] = dp[i - 1][j - 1];
						}
					}
					else{
						if (i == 0){
							dp[i][j] = dp[i][j - 1] + 1;
						}
						else{
							dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
						}
					}
				}
				else{
					if (j == i){
						dp[i][j] = 0;
					}
					else{
						dp[i][j] = dp[i][j - 1];
					}
				}
			}
		}
		return dp[T.size() - 1][S.size() - 1];
	}
};

int main(){
	return 0;
}